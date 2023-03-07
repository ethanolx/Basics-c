#ifndef UTIL_TESTS_H
#define UTIL_TESTS_H

#include "util-configs.h"
#include "util-libs.h"
#include "util-types.h"
#include "util-strings.h"

// Testing Infrastructure
void register_test(const int topic_no, const int q_no, const char category[],
                   const int num_tests, const callback_handler handler);
bool open_file(const char[], const char[], const callback_handler, char[]);

#endif
