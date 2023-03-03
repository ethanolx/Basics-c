#ifndef SUFFIX_C
#define SUFFIX_C

#include "suffix.h"

char* get_suffix(const long long n) {
  if ((n % 100) > 10 && (n % 100) < 20) {
    return "th";
  }
  else if (n % 10 == 1) {
    return "st";
  }
  else if (n % 10 == 2) {
    return "nd";
  }
  else if (n % 10 == 3) {
    return "rd";
  }
  else {
    return "th";
  }
}

char* print_with_suffix(const long long n) {
  char* suffix = get_suffix(n);
  char* with_suffix;
  sprintf(with_suffix, "%lld%s", n, suffix);
  return with_suffix;
}

bool suffix_handler(const char in_buffer[][MAX_LINE_LENGTH],
                    const int num_lines,
                    const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long long n;
  sscanf(in_buffer[0], "%lld", &n);

  // Expected
  const char* num_with_suffix_exp = out_buffer[0];

  // Actual
  char* num_with_suffix = print_with_suffix(n);

  if (!equal_char_arrays(num_with_suffix, num_with_suffix_exp)) {
    sprintf(message, "Suffix: Expected %s but received %s", num_with_suffix_exp,
            num_with_suffix);
    return false;
  }

  return true;
}

#endif
