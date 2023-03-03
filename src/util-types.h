#ifndef UTIL_TYPES_H
#define UTIL_TYPES_H

#include "util-configs.h"

typedef bool (*callback_handler)(const char in_buffer[][MAX_LINE_LENGTH],
                                 const int num_lines,
                                 const char out_buffer[][MAX_LINE_LENGTH],
                                 char message[]);

#endif
