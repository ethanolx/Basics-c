#ifndef TAXI_H
#define TAXI_H

#include "../utils.h"

bool is_weekday(int);
bool is_morning_peak_hour(double);
bool is_evening_peak_hour(double);
bool is_midnight_peak_hour(double);
double calculate_basic_fare(long);
double calculate_surcharge(long, long, long, double);
double calculate_fare(long, long, long, long);

bool taxi_handler(const char[][MAX_LINE_LENGTH], const int,
                  const char[][MAX_LINE_LENGTH], char[]);

#endif
