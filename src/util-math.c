#ifndef UTIL_MATH_C
#define UTIL_MATH_C

#include "util-math.h"

double round_p(const double x, const int precision) {
  double factor = pow(10.0, precision);
  return round(x * factor) / factor;
}

#endif
