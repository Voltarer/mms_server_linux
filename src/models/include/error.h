#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <string.h>
#include <errno.h>

// Базовые макросы (без порта)
#define LOG_ERROR(msg) \
    do { \
        fprintf(stderr, "[ERROR] %s: %s (errno=%d)\n", msg, strerror(errno), errno); \
    } while(0)

#define LOG_ERROR_DETAILED(msg) \
    do { \
        fprintf(stderr, "[ERROR] %s (%s:%d in %s): %s\n", msg, __FILE__, __LINE__, __func__, strerror(errno)); \
    } while(0)

// Макросы с указанием порта
#define LOG_ERROR_PORT(port, msg) \
    do { \
        fprintf(stderr, "[ERROR] Порт %d: %s: %s (errno=%d)\n", port, msg, strerror(errno), errno); \
    } while(0)

#define LOG_ERROR_PORT_DETAILED(port, msg) \
    do { \
        fprintf(stderr, "[ERROR] Порт %d: %s (%s:%d in %s): %s\n", port, msg, __FILE__, __LINE__, __func__, strerror(errno)); \
    } while(0)

// Проверки с возвратом -1 (без порта)
#define CHECK_SYSCALL(expr) \
    do { \
        if ((expr) < 0) { \
            LOG_ERROR_DETAILED(#expr); \
            return -1; \
        } \
    } while(0)

#define CHECK_COND(cond, msg) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "[ERROR] %s\n", msg); \
            return -1; \
        } \
    } while(0)

// Проверки с портом
#define CHECK_SYSCALL_PORT(expr, port) \
    do { \
        if ((expr) < 0) { \
            LOG_ERROR_PORT_DETAILED(port, #expr); \
            return -1; \
        } \
    } while(0)

#define CHECK_COND_PORT(cond, port, msg) \
    do { \
        if (!(cond)) { \
            fprintf(stderr, "[ERROR] Порт %d: %s\n", port, msg); \
            return -1; \
        } \
    } while(0)

#endif // ERROR_H