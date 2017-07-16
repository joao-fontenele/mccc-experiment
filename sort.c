#include "sort.h"

void swap (int *x, int *y) {
  int aux;

  aux = *x;
  *x = *y;
  *y = aux;
}

int partition(int *array, int lo, int hi) {
  int i;
  int j;

  for (i = lo, j = lo + 1; j <= hi; j++) {
    if (array[j] >= array[lo]) continue;

    i++;
    swap(&array[i], &array[j]);
  }
  swap(&array[lo], &array[i]);

  return i;
}

int randomPartition(int *array, int lo, int hi) {
  srand(time(NULL));
  int random = (rand() % (hi - lo + 1)) + lo;
  swap(&array[lo], &array[random]);
  return partition(array, lo, hi);
}

void _quicksort(int *array, int lo, int hi, int (*partitionate) (int*, int, int)) {
  int pivot = 0;

  if (hi > lo) {
    pivot = partitionate(array, lo, hi);
    _quicksort(array, lo, pivot - 1, partitionate);
    _quicksort(array, pivot + 1, hi, partitionate);
  }
}

void quicksort(int *array, int n) {
  _quicksort(array, 0, n - 1, partition);
}

void quicksortRandom(int *array, int n) {
  _quicksort(array, 0, n - 1, randomPartition);
}

void bubblesort(int *array, int n) {
    int top = n;
    int newTop = 0;

    while (top > 0) {
      newTop = 0;
      for (int i = 1; i < n; i++) {
          if (array[i - 1] > array[i]) {
              swap(&array[i - 1], &array[i]);
              newTop = i;
          }
      }
      top = newTop;
    }
}
