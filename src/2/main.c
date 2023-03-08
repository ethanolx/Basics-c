#ifndef MAIN
#define MAIN

#include "../utils.h"
#include "collatz.h"
#include "rectangle.h"
#include "prime.h"
#include "pattern.h"

int main(int argc, char* argv[]) {
  register_test(2, 1, "collatz", 7, collatz_handler);
  register_test(2, 2, "rectangle", 4, rectangle_handler);
  register_test(2, 3, "prime", 19, prime_handler);
  register_test(2, 4, "pattern", 11, pattern_handler);

  return 0;
}

#endif
