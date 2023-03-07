#ifndef RECTANGLE_C
#define RECTANGLE_C

#include "rectangle.h"

#define BOTTOM_LEFT '4'
#define BOTTOM_RIGHT '3'
#define HORIZONTAL_EDGE '-'
#define TOP_LEFT '1'
#define TOP_RIGHT '2'
#define VERTICAL_EDGE '|'

char* get_rectangle_row(const int width, const int height,
                        const int row_index) {
  // Instantiate the row container
  char* row = malloc(sizeof(char) * (width + 2));
  row[width] = '\n';
  row[width + 1] = '\0';

  for (int j = 0; j < width; j++) {
    // Top row
    if (row_index == 0) {
      // Corners
      if (j == 0) {
        row[j] = TOP_LEFT;
      }
      else if (j == width - 1) {
        row[j] = TOP_RIGHT;
      }
      // Edge
      else {
        row[j] = HORIZONTAL_EDGE;
      }
    }
    // Bottom row
    else if (row_index == height - 1) {
      // Corners
      if (j == 0) {
        row[j] = BOTTOM_LEFT;
      }
      else if (j == width - 1) {
        row[j] = BOTTOM_RIGHT;
      }
      // Edge
      else {
        row[j] = HORIZONTAL_EDGE;
      }
    }
    // Other rows
    else {
      // Edge
      if ((j == 0) || (j == width - 1)) {
        row[j] = VERTICAL_EDGE;
      }
      // Internal space
      else {
        row[j] = ' ';
      }
    }
  }

  return row;
}

bool rectangle_handler(const char in_buffer[][MAX_LINE_LENGTH],
                       const int num_lines,
                       const char out_buffer[][MAX_LINE_LENGTH],
                       char message[]) {
  int width, height;
  sscanf(in_buffer[0], "%d %d", &width, &height);

  for (int i = 0; i < height; i++) {
    // Expected
    const char* row_exp = out_buffer[i];

    // Actual
    char* row = get_rectangle_row(width, height, i);

    if (strcmp(row_exp, row) != 0) {
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
