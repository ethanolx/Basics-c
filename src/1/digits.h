#ifndef DIGITS_H
#define DIGITS_H

#include "../utils.h"

long cube(long);
long sum_of_digits_cubed(long long);

bool digits_handler(const char[][MAX_LINE_LENGTH], const int,
                    const char[][MAX_LINE_LENGTH], char[]);

#endif
