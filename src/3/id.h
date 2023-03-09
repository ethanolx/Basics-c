#ifndef ID_H
#define ID_H

#include "../utils.h"

const int sum_digits(const char*);
const int calculate_remainder(const int);
const char get_check_code(const int);

bool id_handler(const char[][MAX_LINE_LENGTH], const int,
                const char[][MAX_LINE_LENGTH], char[]);

#endif
