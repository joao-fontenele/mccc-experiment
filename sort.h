#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y);

int partition(int *array, int lo, int hi);
void _quicksort(int *array, int lo, int hi);
void quicksort(int *array, int n);

#endif
