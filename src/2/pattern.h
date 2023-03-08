#ifndef PATTERN_H
#define PATTERN_H

#include "../utils.h"
#include "prime.h"

int get_leading_num(const int, const int);
bool cell_contains_prime(const int, const int, const int);
char* get_pattern(const int, const int, const int);

bool pattern_handler(const char[][MAX_LINE_LENGTH], const int,
                     const char[][MAX_LINE_LENGTH], char[]);

#endif
