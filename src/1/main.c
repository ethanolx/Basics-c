#ifndef MAIN
#define MAIN

#include "../utils.h"
#include "cuboid.h"
#include "digits.h"
#include "suffix.h"
#include "taxi.h"

int main(int argc, char* argv[]) {
  register_test(1, 1, "cuboid", 4, cuboid_handler);
  register_test(1, 2, "digits", 5, digits_handler);

  return 0;
}

#endif
