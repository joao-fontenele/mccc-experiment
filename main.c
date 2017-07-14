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
  };
  int sortsSize = 1;

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

int main(int argc, char *argv[]) {
  int reps = 3;
  int n = 500;

  printHeader(reps);
  runExperiment(n, reps);
  return 0;
}
