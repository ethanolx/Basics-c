#ifndef MAIN
#define MAIN

#include "../utils.h"
#include "collatz.h"

int main(int argc, char* argv[]) {
  register_test(2, 1, "collatz", 7, collatz_handler);

  return 0;
}

#endif
