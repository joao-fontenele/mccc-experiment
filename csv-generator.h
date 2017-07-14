#ifndef CSV_GENERATOR_H_
#define CSV_GENERATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "array.h"

double timeSortFunction(void (*sort) (int*, int), int *array, int n);
void printHeader(int reps);
void printLine(char *sortName, char *arrayType, void (*sort) (int*, int),
    int* (*getArray) (int), int n, int reps);

#endif
