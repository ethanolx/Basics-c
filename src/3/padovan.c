#ifndef PADOVAN_C
#define PADOVAN_C

#include "padovan.h"

long padovan(bool cache_status[], long cache[], const long i) {
  if (cache_status[i]) {
    return cache[i];
  }

  const int p =
      padovan(cache_status, cache, i - 2) + padovan(cache_status, cache, i - 3);

  // Cache the values - dynamic programming
  cache_status[i] = true;
  cache[i] = p;

  return p;
}

bool padovan_handler(const char in_buffer[][MAX_LINE_LENGTH],
                     const int num_lines,
                     const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  int n;
  sscanf(in_buffer[0], "%d", &n);

  // Instantiate cache
  const int upper_limit = 1000;
  bool cache_status[upper_limit];
  long cache[upper_limit];

  // Initiate base conditions
  for (int i = 0; i < upper_limit; i++) {
    cache_status[i] = (i <= 2);
  }
  cache[0] = 1;
  cache[1] = 0;
  cache[2] = 0;

  for (int i = 0; i <= n; i++) {
    // Expected
    long padovan_val_exp;
    sscanf(out_buffer[i], "%ld", &padovan_val_exp);

    // Actual
    long padovan_val = padovan(cache_status, cache, n - i);

    if (padovan_val != padovan_val_exp) {
      sprintf(message, "Padovan: Expected %ld but received %ld",
              padovan_val_exp, padovan_val);
      return false;
    }
  }

  return true;
}

#endif
