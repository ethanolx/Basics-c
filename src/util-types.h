#ifndef UTIL_TYPES_H
#define UTIL_TYPES_H

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 20
#define MAX_PATH_LENGTH 40
#define MAX_MESSAGE_LENGTH 50

#include <stdbool.h>

typedef bool (*callback_handler)(const char in_buffer[][MAX_LINE_LENGTH],
                                 const int num_lines,
                                 const char out_buffer[][MAX_LINE_LENGTH],
                                 char message[]);

#endif
