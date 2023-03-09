#ifndef ID_C
#define ID_C

#include "days.h"

const int sum_digits(const char* student_id) {
  int sum = 0;
  for (int i = 0; i < strlen(student_id) - 1; i++) {
    sum += (int)(student_id[i] - '0');
  }
  return sum;
}

const int calculate_remainder(const int sum_of_digits) {
  return sum_of_digits % 13;
}

const char get_check_code(const int r) {
  const char check_codes[13] = {'Y', 'X', 'W', 'U', 'R', 'N', 'M',
                                'L', 'J', 'H', 'E', 'A', 'B'};
  return check_codes[r];
}

bool id_handler(const char in_buffer[][MAX_LINE_LENGTH], const int num_lines,
                const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  const char* student_id = in_buffer[0];

  // Expected
  char check_code_exp;
  sscanf(out_buffer[0], "%c", &check_code_exp);

  // Actual
  int check_code = get_check_code(calculate_remainder(sum_digits(student_id)));

  if (check_code != check_code_exp) {
    sprintf(message, "Check Code: Expected %c but received %c", check_code_exp,
            check_code);
    return false;
  }

  return true;
}

#endif
