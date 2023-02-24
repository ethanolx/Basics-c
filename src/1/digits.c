#ifndef DIGITS
#define DIGITS

#include "digits.h"

long cube(long num) { return num * num * num; }

long sum_of_digits_cubed(long num) {
  if (num > 0) {
    return sum_of_digits_cubed(num / 10) + cube(num % 10);
  }

  return 0;
}

#endif
