#ifndef UTILS_H
#define UTILS_H

#include "util-types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void register_test(const int topic_no, const int q_no, const char category[],
                   const int num_tests, const callback_handler handler);

bool open_file(const char[], const char[], const callback_handler, char[]);

#endif
