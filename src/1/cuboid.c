#ifndef CUBOID_C
#define CUBOID_C

#include "cuboid.h"

double hypotenuse_of(long a, long b, long c) {
  double _a = (double)a;
  double _b = (double)b;
  double _c = (double)c;
  return pow(pow(_a, 2.0) + pow(_b, 2.0) + pow(_c, 2.0), 0.5);
}

long area_of_rectangle(long a, long b, long c) {
  return 2 * a * b + 2 * b * c + 2 * a * c;
}

bool cuboid_handler(const char in_buffer[][MAX_LINE_LENGTH],
                    const int num_lines,
                    const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long a, b, c;
  sscanf(in_buffer[0], "%ld %ld %ld", &a, &b, &c);

  // Expected
  double hyp_exp;
  long area_exp;
  sscanf(out_buffer[0], "%ld", &area_exp);
  sscanf(out_buffer[1], "%lf", &hyp_exp);

  // Actual
  double hyp = round_p(hypotenuse_of(a, b, c), 4);
  long area = area_of_rectangle(a, b, c);

  if (hyp != hyp_exp) {
    sprintf(message, "Hypotenuse: Expected %lf but received %lf", hyp_exp, hyp);
    return false;
  }
  if (area != area_exp) {
    sprintf(message, "Area: Expected %ld but received %ld", area_exp, area);
    return false;
  }

  return true;
}

#endif
