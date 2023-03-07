#ifndef PRIME_C
#define PRIME_C

#include "prime.h"

bool is_prime(long long x) {
  for (long long i = 2; i <= pow(x, 0.5); i++) {
    if (x % i == 0) {
      return false;
    }
  }

  return true;
}

long long get_largest_prime(long long n) {
  for (long long i = n; i > 0; i--) {
    if (is_prime(i)) {
      return i;
    }
  }

  return 2;
}

bool prime_handler(const char in_buffer[][MAX_LINE_LENGTH], const int num_lines,
                   const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long long n;
  sscanf(in_buffer[0], "%lld", &n);

  // Expected
  long long largest_prime_exp;
  sscanf(out_buffer[0], "%lld", &largest_prime_exp);

  // Actual
  long long largest_prime = get_largest_prime(n);

  if (largest_prime != largest_prime_exp) {
    sprintf(message, "Largest Prime: Expected %lld but received %lld",
            largest_prime_exp, largest_prime);
    return false;
  }

  return true;
}

#endif
