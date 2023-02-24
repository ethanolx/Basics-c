#ifndef CUBOID
#define CUBOID

#include "cuboid.h"
#include "math.h"

double hypotenuse_of(long a, long b, long c) {
  double _a = (double)a;
  double _b = (double)b;
  double _c = (double)c;
  return pow(pow(_a, 2.0) + pow(_b, 2.0) + pow(_c, 2.0), 0.5);
}

long area_of_rectangle(long a, long b, long c) {
  return 2 * a * b + 2 * b * c + 2 * a * c;
}

#endif
