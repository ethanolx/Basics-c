#ifndef SUFFIX_H
#define SUFFIX_H

#include "../utils.h"

char* get_suffix(const long long);
char* print_with_suffix(const long long);

bool suffix_handler(const char[][MAX_LINE_LENGTH], const int,
                    const char[][MAX_LINE_LENGTH], char[]);

#endif
