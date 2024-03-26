#include <stdio.h>
#include "logger.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

log_level_t log_level = LOG_INFO;

int logger(const char *filename, const log_level_t level) {
    int log_fd = open(filename, O_WRONLY | O_CREAT, 0644);
    if (log_fd == -1) {
        perror("Failed to open log file");
        return LOG_FAILURE;
    }

    log_level = level;

    return log_fd;
}

int log_msg(int log_fd, char *msg, log_level_t level) {

    if (level < log_level) {
        write(log_fd, "too low of a level", strlen("too low of a level"));
        return LOG_SUCCESS;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char year[5];
    char month[3];
    char day[3];
    char hour[3];
    char minute[3];
    char second[3];

    strftime(year, 5, "%Y", t);
    strftime(month, 3, "%m", t);
    strftime(day, 3, "%d", t);
    strftime(hour, 3, "%H", t);
    strftime(minute, 3, "%M", t);
    strftime(second, 3, "%S", t);

    char timestamp[20];

    timestamp[0] = '\0';
    strcat(timestamp, year);
    strcat(timestamp, "-");
    strcat(timestamp, month);
    strcat(timestamp, "-");
    strcat(timestamp, day);
    strcat(timestamp, " ");
    strcat(timestamp, hour);
    strcat(timestamp, ":");
    strcat(timestamp, minute);
    strcat(timestamp, ":");
    strcat(timestamp, second);
    strcat(timestamp, " ");

    if (write(log_fd, timestamp, strlen(timestamp)) == -1) {
        return LOG_FAILURE;
    }


    switch (level) {
        case LOG_INFO:
            if (write(log_fd, "INFO: ", 6) == -1) {
                return LOG_FAILURE;
            }
            break;
        case LOG_DEBUG:
            if (write(log_fd, "DEBUG: ", 7) == -1) {
                return LOG_FAILURE;
            }
            break;
        case LOG_WARNING:
            if (write(log_fd, "WARNING: ", 9) == -1) {
                return LOG_FAILURE;
            }
            break;
        case LOG_ERROR:
            if (write(log_fd, "ERROR: ", 7) == -1) {
                return LOG_FAILURE;
            }
            break;
        default:
            return LOG_FAILURE;

    }

    if (write(log_fd, msg, strlen(msg)) == -1) {
        return LOG_FAILURE;
    }

    if (write(log_fd, "\n", 1) == -1) {
        return LOG_FAILURE;
    }

    return LOG_SUCCESS;
}


