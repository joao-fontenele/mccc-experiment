#ifndef SORT_H_
#define SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "array.h"

void swap(int *x, int *y);

int partition(int *array, int lo, int hi);
int randomPartition(int *array, int lo, int hi);
void _quicksort(int *array, int lo, int hi, int (*partitionate) (int*, int, int));
void quicksort(int *array, int n);
void quicksortRandom(int *array, int n);

void bubblesort(int *array, int n);

#endif
