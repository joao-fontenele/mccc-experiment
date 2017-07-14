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

void _quicksort(int *array, int lo, int hi) {
  int q = 0;

  if (hi > lo) {
    q = partition(array, lo, hi);
    _quicksort(array, lo, q - 1);
    _quicksort(array, q + 1, hi);
  }
}

void quicksort(int *array, int n) {
  _quicksort(array, 0, n - 1);
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
