#ifndef MAX_C
#define MAX_C

#include "max.h"

long find_max(const long list[], long start, long end) {
  // Last element
  if (start == end - 1) {
    return list[start];
  }

  const long max_of_remainder = find_max(list, start + 1, end);

  return list[start] > max_of_remainder ? list[start] : max_of_remainder;
}

bool max_handler(const char in_buffer[][MAX_LINE_LENGTH], const int num_lines,
                 const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  int k;
  sscanf(in_buffer[0], "%d", &k);
  long L[k];
  for (int i = 0; i < k; i++) {
    long el;
    sscanf(in_buffer[i + 1], "%ld", &el);

    L[i] = el;
  }

  // Expected
  long max_el_exp;
  sscanf(out_buffer[0], "%ld", &max_el_exp);

  // Actual
  long max_el = find_max(L, 0, k);

  if (max_el != max_el_exp) {
    sprintf(message, "Max: Expected %ld but received %ld", max_el_exp, max_el);
    return false;
  }

  return true;
}

#endif
