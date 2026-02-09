#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>      
#include <sys/time.h>    
#include <locale.h>

#include "iec61850_server.h"
#include "static_model.h"

extern IedModel iedModel;

uint64_t get_precise_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}

float get_ram_load() {
    FILE* fp = fopen("/proc/meminfo", "r");
    if (!fp) return 0.0f;
    long total = 0, available = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total) == 1) continue;
        if (sscanf(line, "MemAvailable: %ld kB", &available) == 1) break;
    }
    fclose(fp);
    return (total > 0) ? (float)(total - available) / (float)total * 100.0f : 0.0f;
}

void init_switch_nodes(IedServer server) {
    char objRef[100];
    
    for (int i = 1; i <= 7; i++) {
        sprintf(objRef, "LD0/LCCH%d.ChLiv.stVal", i);
        DataAttribute* chLiv = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, objRef);
        if (chLiv) IedServer_updateBooleanAttributeValue(server, chLiv, true);

        sprintf(objRef, "LD0/LCCH%d.RxCnt.actVal", i);
        DataAttribute* rx = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, objRef);
        if (rx) IedServer_updateInt64AttributeValue(server, rx, 0);

        sprintf(objRef, "LD0/LCCH%d.TxCnt.actVal", i);
        DataAttribute* tx = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, objRef);
        if (tx) IedServer_updateInt64AttributeValue(server, tx, 0);
    }

    for (int i = 1; i <= 6; i++) {
        sprintf(objRef, "LD0/LPCP%d.PhyHealth.stVal", i);
        DataAttribute* health = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, objRef);
        if (health) IedServer_updateInt32AttributeValue(server, health, 1);

        sprintf(objRef, "LD0/LPCP%d.LinkSt.stVal", i);
        DataAttribute* link = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, objRef);
        if (link) IedServer_updateBooleanAttributeValue(server, link, true);
    }
}

int main(int argc, char** argv) {

    IedServer iedServer = IedServer_create(&iedModel);
    if (iedServer == NULL) {
        printf("Ошибка: не удалось создать сервер.\n");
        return 1;
    }

    IedServer_start(iedServer, 102);
    if (!IedServer_isRunning(iedServer)) {
        printf("Ошибка: сервер не запущен\n");
        IedServer_destroy(iedServer);
        return 1;
    }

    init_switch_nodes(iedServer);

    printf("MMS Server запущен \n");

    while (1) {
        uint64_t timestampPtr = get_precise_time_ms();
        Timestamp iecTimestamp;
        Timestamp_clearFlags(&iecTimestamp);
        Timestamp_setTimeInMilliseconds(&iecTimestamp, timestampPtr);

        float currentRam = get_ram_load();
        DataAttribute* ramAttr = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, "LD0/GGIO1.AnIn1.mag.f");
        if (ramAttr) {
            IedServer_updateFloatAttributeValue(iedServer, ramAttr, currentRam);
            
            DataAttribute* ramT = (DataAttribute*)IedModel_getModelNodeByShortObjectReference(&iedModel, "LD0/GGIO1.AnIn1.t");
            if (ramT) IedServer_updateTimestampAttributeValue(iedServer, ramT, &iecTimestamp);
        }

        printf("\r[Статус] RAM : %.2f%%", currentRam);
        fflush(stdout);

        usleep(1000000);
    }

    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    return 0;
}