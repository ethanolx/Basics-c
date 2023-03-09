#ifndef DAYS_H
#define DAYS_H

#include "../utils.h"

const int days_until_month(const int);

bool days_handler(const char[][MAX_LINE_LENGTH], const int,
                  const char[][MAX_LINE_LENGTH], char[]);

#endif
