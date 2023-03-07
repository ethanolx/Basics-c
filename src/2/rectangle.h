#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../utils.h"

char* get_rectangle_row(const int, const int, const int);

bool rectangle_handler(const char[][MAX_LINE_LENGTH], const int,
                       const char[][MAX_LINE_LENGTH], char[]);

#endif
