#include "csv-generator.h"

// returns runtime in seconds
double timeSortFunction(void (*sort) (int*, int), int *array, int n) {
  struct timeval init;
  struct timeval end;

  gettimeofday(&init, NULL);
  sort(array, n);
  gettimeofday(&end, NULL);

  return (end.tv_sec * 1.0 + end.tv_usec / 1000000.0)
    - (init.tv_sec * 1.0 + init.tv_usec / 1000000.0);
}

void printHeader(int reps) {
  printf("sort"); // prints header for sort function name
  printf(",type"); // prints header for array type
  printf(",n"); // prints header for the array size

  // prints the numer of the repetition, column headers
  for (int i = 0; i < reps; i++) {
    printf(",%d", i);
  }

  // prints the average header
  printf(",avg\n");
}

void printLine(
    char *sortName, // name of the sort function
    char *arrayType, // name of the array generation method
    void (*sort) (int*, int), // pointer to a sort function
    int* (*getArray) (int), // pointer to an array generator function
    int n, // size of the array to be generated and sorted
    int reps // amount of repetitions to time the sorting of the generated array
  ) {
  int *array = getArray(n);
  double totalTime = 0.0;
  double thisTime = 0.0;

  // prints header for sort function name, and array type
  printf("%s,%s,%d", sortName, arrayType, n);

  for (int i = 0; i < reps; i++) {
    thisTime = timeSortFunction(sort, array, n);
    printf(",%lf", thisTime); // prints the time of this rep
    totalTime += thisTime;
  }

  // prints the average time of all reps
  printf(",%lf\n", totalTime / reps); // prints the time of this rep

  freeArray(array);
}
