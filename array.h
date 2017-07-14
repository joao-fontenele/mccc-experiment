#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocateArray(int n);
int* freeArray(int *array);

int* getRandomArray(int n);
int* getOrderedArray(int n);
int* getReverseArray(int n);
int* getRepeatedArray(int n);

void printArray(int *array, int n);

#endif
