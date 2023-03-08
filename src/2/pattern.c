#ifndef PATTERN_C
#define PATTERN_C

#include "pattern.h"

int get_leading_num(const int row, const int m) {
  return arithmetic_sum(1, row) * m + 1;
}

bool cell_contains_prime(const int row, const int col, const int m) {
  int leading_num = get_leading_num(row, m);

  for (int i = 0; i < m; i++) {
    if (is_prime(leading_num + (row + 1) * i + col)) {
      return true;
    }
  }

  return false;
}

char* get_pattern(const int m, const int height, const int row_index) {
  const int width = 2 * height - 1;

  int current_row_width = 2 * row_index + 1;
  int row_start = (width - current_row_width) / 2;
  int row_end = width - ((width - current_row_width) / 2);

  char* row = malloc(sizeof(char) * (width + 2));
  row[width] = '\n';
  row[width + 1] = '\0';

  for (int j = 0; j < width; j++) {
    if (j < row_start || j >= row_end) {
      row[j] = ' ';
    }
    else if (cell_contains_prime(row_index, j - row_start, m)) {
      row[j] = '#';
    }
    else {
      row[j] = '.';
    }
  }

  return row;
}

bool pattern_handler(const char in_buffer[][MAX_LINE_LENGTH],
                     const int num_lines,
                     const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  int m, height;
  sscanf(in_buffer[0], "%d %d", &m, &height);

  for (int i = 0; i < height; i++) {
    // Expected
    const char* row_exp = out_buffer[i];

    // Actual
    char* row = get_pattern(m, height, i);

    if (strcmp(row, row_exp) != 0) {
      sprintf(message, "Row: Expected \"%s\" but received \"%s\"", row_exp,
              row);

      free(row);
      return false;
    }

    free(row);
  }

  return true;
}

#endif
