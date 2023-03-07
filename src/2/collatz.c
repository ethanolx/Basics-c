#ifndef COLLATZ_C
#define COLLATZ_C

#include "collatz.h"

int collatz(const long long x) {
  // Cannot be negative
  if (x < 0) {
    return -1;
  }

  // Termination clause
  if (x == 1) {
    return 0;
  }

  // Determine the next number using the pattern:
  //  +- x / 2, x is even
  // -|
  //  +- 3x + 1, x is odd
  long long next_num = (x % 2 == 0) ? x / 2 : 3 * x + 1;

  return collatz(next_num) + 1;
}

void compare_stopping_time(const long long a, const long long b,
                           int* longest_stopping_time, long long* corr_seed) {
  // Initial conditions
  *longest_stopping_time = collatz(a);
  *corr_seed = a;

  for (long long i = a + 1; i <= b; i++) {
    const int collatz_i = collatz(i);
    if (collatz_i > (*longest_stopping_time)) {
      *longest_stopping_time = collatz_i;
      *corr_seed = i;
    }
    else if (collatz_i == (*longest_stopping_time)) {
      *corr_seed = i;
    }
  }
}

bool collatz_handler(const char in_buffer[][MAX_LINE_LENGTH],
                     const int num_lines,
                     const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long long a, b;
  sscanf(in_buffer[0], "%lld %lld", &a, &b);

  // Expected
  int stop_time_exp;
  long long corr_seed_exp;
  sscanf(out_buffer[0], "%d", &stop_time_exp);
  sscanf(out_buffer[1], "%lld", &corr_seed_exp);

  // Actual
  int stop_time;
  long long corr_seed;
  compare_stopping_time(a, b, &stop_time, &corr_seed);

  if (corr_seed != corr_seed_exp) {
    sprintf(message, "Corresponding Seed: Expected %lld but received %lld",
            corr_seed_exp, corr_seed);
    return false;
  }

  if (stop_time != stop_time_exp) {
    sprintf(message, "Stop Time: Expected %d but received %d", stop_time_exp,
            stop_time);
    return false;
  }

  return true;
}

#endif
