#include "logger.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



int test_write_log() {
    const int log_fd = logger("test.log", LOG_DEBUG);

    if (log_fd < 0) {
        return -1;
    }

    if (log_msg(log_fd, "this is an info test message", LOG_INFO) < 0) {
        printf("Failed to write log message\n");
        return false;
    }

    if (log_msg(log_fd, "this is an debug test message", LOG_DEBUG) < 0) {
        printf("Failed to write log message\n");
        return false;
    }

    if (log_msg(log_fd, "this is a warning test message", LOG_WARNING) < 0) {
        printf("Failed to write log message\n");
        return false;
    }

    if (log_msg(log_fd, "this is an error test message", LOG_ERROR) < 0) {
        printf("Failed to write log message\n");
        return false;
    }

    return true;

}

int main(){

    bool result = test_write_log();

    return result ? EXIT_SUCCESS : EXIT_FAILURE;
}
