#ifndef COLLATZ_H
#define COLLATZ_H

#include "../utils.h"

int collatz(const long long);

void compare_stopping_time(const long long, const long long, int*, long long*);

bool collatz_handler(const char[][MAX_LINE_LENGTH], const int,
                     const char[][MAX_LINE_LENGTH], char[]);

#endif
