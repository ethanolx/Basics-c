#ifndef DIGITS_C
#define DIGITS_C

#include "digits.h"

long cube(long num) { return num * num * num; }

long sum_of_digits_cubed(long long num) {
  if (num > 0) {
    return sum_of_digits_cubed(num / 10) + cube(num % 10);
  }

  return 0;
}

bool digits_handler(const char in_buffer[][MAX_LINE_LENGTH],
                    const int num_lines,
                    const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long long a;
  sscanf(in_buffer[0], "%lld", &a);

  // Expected
  long sum_exp;
  sscanf(out_buffer[0], "%ld", &sum_exp);

  // Actual
  long sum = sum_of_digits_cubed(a);

  if (sum != sum_exp) {
    sprintf(message, "Sum: Expected %ld but received %ld", sum_exp, sum);
    return false;
  }

  return true;
}

#endif
