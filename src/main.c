#define _GNU_SOURCE
#include "hal_thread.h"
#include "hal_time.h"
#include "iec61850_server.h"
#include "mms_common.h"
#include "static_model.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifndef _WIN32
    #include <sys/socket.h>
    #include <linux/rtnetlink.h>
    #include <unistd.h>
#endif

#define TOTAL_PORTS 28

/* Прототипы внешних функций для работы с "железом" MIPS */
extern int get_hardware_port_status(int port_idx, int nl_fd);
extern int set_hardware_port_status(int port_idx, int enable);

static int running = 1;
void sigint_handler(int signalId) { running = 0; }

/* Массив указателей на атрибуты управления (Mau) */
DataAttribute* mauAttrs[TOTAL_PORTS];

/* Обработчик подключений: помогает отлаживать сессии */
static void
connectionHandler(IedServer self, ClientConnection connection, bool created, void* parameter) {
    const char* ipAddr = ClientConnection_getPeerAddress(connection);
    if (ipAddr != NULL) {
        printf("MMS: [%s] Клиент: %s\n", created ? "ПОДКЛЮЧЕНИЕ" : "ОТКЛЮЧЕНИЕ", ipAddr);
    }
}

/* Обработчик записи: выполнение команд управления от клиента */
static MmsDataAccessError
writeAccessHandler(DataAttribute* attr, MmsValue* value, ClientConnection connection, void* parameter)
{
    for (int i = 0; i < TOTAL_PORTS; i++) {
        if (attr == mauAttrs[i]) {
            int newVal = MmsValue_toInt32(value);
            printf("MMS: Команда для порта %d -> значение: %d\n", i + 1, newVal);
            set_hardware_port_status(i, (newVal == 1));
            return DATA_ACCESS_ERROR_SUCCESS;
        }
    }
    return DATA_ACCESS_ERROR_SUCCESS; 
}

int main(int argc, char **argv) {
    signal(SIGINT, sigint_handler);

    IedServer iedServer = IedServer_create(&iedModel);
    IedServer_setConnectionIndicationHandler(iedServer, connectionHandler, NULL);

    /* Привязка атрибутов управления. 
     * ВНИМАНИЕ: Для Mau используется тип INS (Integer Status).
     */
    mauAttrs[0] = IEDMODEL_Bridge_LPCP1_Mau_stVal; 
    
    for (int i = 0; i < TOTAL_PORTS; i++) {
        if (mauAttrs[i] != NULL) {
            IedServer_handleWriteAccess(iedServer, mauAttrs[i], writeAccessHandler, NULL);
        }
    }
    
    IedServer_start(iedServer, 102);

    if (!IedServer_isRunning(iedServer)) {
        printf("Ошибка: запуск сервера на порту 102 не удался. Нужны root-права!\n");
        IedServer_destroy(iedServer);
        return -1;
    }

    int nl_fd = -1;
#ifndef _WIN32
    nl_fd = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
#endif

    printf("MIPS MMS Сервер запущен. Ожидание отчетов...\n");

    int32_t testCounter = 0; // Наш тестовый счетчик

    while (running) {
        uint64_t timeMs = Hal_getTimeInMs();
        
        IedServer_lockDataModel(iedServer);
        
        /* ТЕСТ: Постоянно обновляем NumPwrUp, который точно есть в DataSet ds */
        testCounter++;
        
        // Обновляем значение счетчика
        IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Bridge_LPHD1_NumPwrUp_stVal, testCounter);
        
        // Обновляем время для счетчика, чтобы сработал триггер отчета
        MmsValue* utcTime = MmsValue_newUtcTime(timeMs / 1000);
        MmsValue_setUtcTimeMs(utcTime, timeMs);
        IedServer_updateAttributeValue(iedServer, IEDMODEL_Bridge_LPHD1_NumPwrUp_t, utcTime);
        MmsValue_delete(utcTime);

        /* Основной рабочий код для Mau (оставляем как было) */
        if (nl_fd >= 0) {
            int status = get_hardware_port_status(0, nl_fd); 
            IedServer_updateInt32AttributeValue(iedServer, IEDMODEL_Bridge_LPCP1_Mau_stVal, (int32_t)status);
            
            MmsValue* utcTimeMau = MmsValue_newUtcTime(timeMs / 1000);
            MmsValue_setUtcTimeMs(utcTimeMau, timeMs);
            IedServer_updateAttributeValue(iedServer, IEDMODEL_Bridge_LPCP1_Mau_t, utcTimeMau);
            MmsValue_delete(utcTimeMau);
        }

        IedServer_unlockDataModel(iedServer);
        
        Thread_sleep(1000); // Спим 1 секунду
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    
#ifndef _WIN32
    if (nl_fd >= 0) close(nl_fd);
#endif

    return 0;
}