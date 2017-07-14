#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "array.h"
#include "sort.h"
#include "csv-generator.h"

typedef struct {
  char *name;
  void (*method) (int*, int);
} sortMethod;

typedef struct {
  char *name;
  int* (*method) (int);
} arrayGenerationMethod;

void runExperiment(int n, int reps) {
  sortMethod *sMethod = NULL;
  sortMethod sMethods[] = {
    {.name="quicksort", .method=quicksort},
    {.name="bubblesort", .method= bubblesort},
  };
  int sortsSize = 2;

  arrayGenerationMethod *gMethod = NULL;
  arrayGenerationMethod gMethods[] = {
    {.name="random", .method=getRandomArray},
    {.name="ordered", .method=getOrderedArray},
    {.name="reversed", .method=getReverseArray},
    {.name="repeated", .method=getRepeatedArray},
  };
  int generationsSize = 4;

  for (int i = 0; i < sortsSize; i++) {
    sMethod = &sMethods[i];
    for (int j = 0; j < generationsSize; j++) {
      gMethod = &gMethods[j];
      printLine(sMethod->name, gMethod->name, sMethod->method, gMethod->method,
          n, reps);
    }
  }
}

void testSort(void (*sort) (int*, int), int* (*getArray) (int), int n) {
  int *array = getArray(n);

  printArray(array, n);
  sort(array, n);
  printArray(array, n);

  freeArray(array);
}

int main(int argc, char *argv[]) {
  // uncomment to check if the sort methods are working
  // testSort(bubblesort, getRandomArray, 5);
  // testSort(quicksort, getRandomArray, 5);

  if (argc < 3) {
    printf("give me the array size, and number of repetitions to take the average\n");
    printf("ex:\n\t$ ./main <arraySize> <repetitions>\n\t$ ./main 500 5\n");
    return 1;
  }

  int n = atoi(argv[1]);
  int reps = atoi(argv[2]);

  printHeader(reps);
  runExperiment(n, reps);

  return 0;
}
