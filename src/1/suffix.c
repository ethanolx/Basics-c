#ifndef SUFFIX
#define SUFFIX

#include "suffix.h"

void print_with_suffix(long n) {
  if (n > 10 && n < 20) {
    printf("%ldth", n);
  } else if (n % 10 == 1) {
    printf("%ldst", n);
  } else if (n % 10 == 2) {
    printf("%ldnd", n);
  } else if (n % 10 == 3) {
    printf("%ldrd", n);
  } else {
    printf("%ldth", n);
  }
}

#endif
