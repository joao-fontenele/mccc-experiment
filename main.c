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
    {.name="quicksortRandom", .method=quicksortRandom},
    {.name="bubblesort", .method= bubblesort},
  };
  int sortsSize = 3;

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
  // testSort(quicksortRandom, getRandomArray, 5);

  if (argc < 3) {
    printf("give me the number of repetitions to take the average, and the sizes of the arrays\n");
    printf("ex:\n\t$ ./main <repetitions> <...N>\n\t$ ./main 30 50 100 200\n");
    return 1;
  }

  int n = 0;
  int reps = atoi(argv[1]);

  printHeader(reps);
  for (int i = 2; i < argc; i++) {
    n = atoi(argv[i]);
    runExperiment(n, reps);
  }

  return 0;
}
