#ifndef MAIN
#define MAIN

#include "../utils.h"
#include "days.h"
#include "id.h"
#include "max.h"
#include "padovan.h"

int main(int argc, char* argv[]) {
  register_test(3, 1, "days", 18, days_handler);
  register_test(3, 2, "id", 16, id_handler);
  register_test(3, 3, "max", 8, max_handler);
  register_test(3, 4, "padovan", 12, padovan_handler);

  return 0;
}

#endif
