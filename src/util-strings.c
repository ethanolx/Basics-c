#ifndef UTIL_STRINGS_C
#define UTIL_STRINGS_C

#include "util-strings.h"

char* uppercase(const char lowercase[]) {
  unsigned long length = strlen(lowercase);
  char* upper = malloc(sizeof(char) * (length + 1));
  for (unsigned long i = 0; i <= length; i++) {
    upper[i] = toupper(lowercase[i]);
  }

  return upper;
}

#endif
