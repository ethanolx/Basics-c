#ifndef PRIME_H
#define PRIME_H

#include "../utils.h"

bool is_prime(long long);
long long get_largest_prime(long long);

bool prime_handler(const char[][MAX_LINE_LENGTH], const int,
                   const char[][MAX_LINE_LENGTH], char[]);

#endif
