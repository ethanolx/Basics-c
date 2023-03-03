#ifndef UTIL_CMP_C
#define UTIL_CMP_C

#include "util-cmp.h"

bool equal_char_arrays(const char a[], const char b[]) {
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

#endif
