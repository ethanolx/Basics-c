#ifndef UTIL_TESTS_C
#define UTIL_TESTS_C

#include "util-tests.h"

void register_test(const int topic_no, const int q_no, const char category[],
                   const int num_tests, const callback_handler handler) {
  char* uppercase_category = uppercase(category);
  printf("QUESTION %d: %s\n", q_no, uppercase_category);
  free(uppercase_category);
  for (int i = 1; i <= num_tests; i++) {
    // Initialize the buffer paths
    char in_buffer[MAX_PATH_LENGTH];
    char out_buffer[MAX_PATH_LENGTH];
    sprintf(in_buffer, "data/%d/inputs/%s.%d.in", topic_no, category, i);
    sprintf(out_buffer, "data/%d/outputs/%s.%d.out", topic_no, category, i);

    char message[MAX_MESSAGE_LENGTH] = "";
    bool passed = open_file(in_buffer, out_buffer, handler, message);

    printf("TEST %d: %s", i, passed ? "PASSED" : "FAILED");
    if (strlen(message) > 0) {
      printf(" [%s]", message);
    }
    printf("\n");
  }
  printf("\n");
}

bool open_file(const char input_file_name[], const char output_file_name[],
               const callback_handler handler, char message[]) {
  // Initialize the file pointers
  FILE* in_file_ptr = fopen(input_file_name, "r");
  FILE* out_file_ptr = fopen(output_file_name, "r");

  // Check if the file was opened successfully
  if (in_file_ptr == NULL || out_file_ptr == NULL) {
    return false;
  }

  // Initialize 2 2D arrays to store the raw characters
  // of the input and output
  char in_buffer[MAX_LINES][MAX_LINE_LENGTH];
  char out_buffer[MAX_LINES][MAX_LINE_LENGTH];

  // Loop over and extract all the data
  // from the source files
  int i = 0;
  while (fgets(in_buffer[i], MAX_LINE_LENGTH, in_file_ptr) != NULL) {
    i++;
  }
  i = 0;
  while (fgets(out_buffer[i], MAX_LINE_LENGTH, out_file_ptr) != NULL) {
    i++;
  }

  // Close the file buffers
  fclose(in_file_ptr);
  fclose(out_file_ptr);

  // Call the test handler and
  // return the test result
  return handler(in_buffer, i, out_buffer, message);
}

#endif
