#ifndef LOGGER_H
#define LOGGER_H

#define LOG_FAILURE -1
#define LOG_SUCCESS 0

extern int log_fd;


typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} log_level_t;


int logger(const char *log_file, log_level_t level);
int log_msg(int log_fd, char *msg, log_level_t level);

#endif // LOGGER_H
