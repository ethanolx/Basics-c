#ifndef SORT
#define SORT

#include "sort.h"

void sort(long arr[], size_t n) {
  // Initialise start and end pointers
  long* start = arr;
  long* end = &arr[n - 1];

  // Create a temporary array to
  // store the sorted array
  int sorted_arr[n];

  for (int i = 0; i < n; i++) {
    if ((*start) < (*end)) {
      // Insert the largest number from the
      // back of the sorted array
      sorted_arr[n - i - 1] = *end;

      // Decrement the end pointer
      end--;
    } else {
      // Insert the largest number from the
      // back of the sorted array
      sorted_arr[n - i - 1] = *start;

      // Increment the start pointer
      start++;
    }
  }

  // Copy over the values to the provided array
  for (int i = 0; i < n; i++) {
    arr[i] = sorted_arr[i];
  }
}

#endif
