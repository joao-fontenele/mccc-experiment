#include "array.h"

int* allocateArray(int n) {
  return (int*) malloc(n * sizeof(int));
}

int* freeArray(int *array) {
  free(array);
  return NULL;
}

int* getRandomArray(int n) {
  srand(time(NULL));

  int *array = allocateArray(n);

  for (int i = 0; i < n; i++) {
    array[i] = rand() % (2 * (n + 1));
  }

  return array;
}

int* getOrderedArray(int n) {
  int *array = allocateArray(n);

  for (int i = 0; i < n; i++) {
    array[i] = i;
  }

  return array;
}

int* getReverseArray(int n) {
  int *array = allocateArray(n);

  for (int i = n - 1; i >= 0; i--) {
    array[n - i - 1] = i;
  }

  return array;
}

int* getRepeatedArray(int n) {
  srand(time(NULL));

  int *array = allocateArray(n);
  int number = rand() % (n + 1);

  for (int i = 0; i < n; i++) {
    array[i] = number;
  }

  return array;
}

void printArray(int *array, int n) {
	if (n > 0) {
		printf("[%d", array[0]);
	}

	for (int i = 1; i < n; i++) {
		printf(", %d", array[i]);
	}

	printf("]\n");
}
