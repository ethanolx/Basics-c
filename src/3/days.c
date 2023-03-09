#ifndef DAYS_C
#define DAYS_C

#include "days.h"

const int days_until_month(const int month) {
  const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int total_days = 0;
  for (int i = 1; i < month; i++) {
    total_days += days[i - 1];
  }
  return total_days;
}

bool days_handler(const char in_buffer[][MAX_LINE_LENGTH], const int num_lines,
                  const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  int month, date;
  sscanf(in_buffer[0], "%d %d", &month, &date);

  // Expected
  int day_of_year_exp;
  sscanf(out_buffer[0], "%d", &day_of_year_exp);

  // Actual
  int day_of_year = days_until_month(month) + date;

  if (day_of_year != day_of_year_exp) {
    sprintf(message, "Days: Expected %d but received %d",
            day_of_year_exp, day_of_year);
    return false;
  }

  return true;
}

#endif
