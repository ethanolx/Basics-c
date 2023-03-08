#ifndef UTIL_MATH_C
#define UTIL_MATH_C

#include "util-math.h"

const double round_p(const double x, const int precision) {
  double factor = pow(10.0, precision);
  return round(x * factor) / factor;
}

const int arithmetic_sum(const int start, const int end) {
  return (((float)start + (float)end) / 2.0) * (end - start + 1);
}

#endif
