#ifndef MAIN
#define MAIN
#define SAMPLES 2
#define SAMPLES_2 4

#include "cuboid.h"
#include "digits.h"
#include "suffix.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  // Question 1: Cuboid
  printf("QUESTION 1: CUBOID\n");
  {
    const long data[SAMPLES][3] = {{3, 4, 12}, {9, 12, 8}};

    for (int i = 0; i < SAMPLES; i++) {
      const long* sides = data[i];

      printf("SAMPLE %d:\n", i + 1);
      printf("%ld %ld %ld\n", sides[0], sides[1], sides[2]);
      printf("%ld\n", area_of_rectangle(sides[0], sides[1], sides[2]));
      printf("%f\n\n", hypotenuse_of(sides[0], sides[1], sides[2]));
    }
  }

  // Question 2: Digits
  printf("QUESTION 2: DIGITS\n");
  {
    const long data[SAMPLES] = {1933091, 10};
    for (int i = 0; i < SAMPLES; i++) {
      const long num = data[i];

      printf("SAMPLE %d:\n", i + 1);
      printf("%ld\n", num);
      printf("%ld\n\n", sum_of_digits_cubed(num));
    }
  }

  // Question 3: Ordinal Suffix
  printf("QUESTION 2: ORDINAL SUFFIX\n");
  {
    const long data[SAMPLES_2] = {2, 13, 412, 3};
    for (int i = 0; i < SAMPLES_2; i++) {
      const long num = data[i];

      printf("SAMPLE %d:\n", i + 1);
      printf("%ld\n", num);
      print_with_suffix(num);
      printf("\n\n");
    }
  }

  return 0;
}

#endif
