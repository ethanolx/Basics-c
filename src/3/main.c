#ifndef MAIN
#define MAIN

#include "../utils.h"
#include "days.h"

int main(int argc, char* argv[]) {
  register_test(3, 1, "days", 18, days_handler);

  return 0;
}

#endif
