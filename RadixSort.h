#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "DArray.h"
#include <math.h>;


int getMax(DArray myArray);

int getDigit(int theMax);

int nthDigit(int element, int digit);

void countSort(DArray & myArray, int exponent);

void radixSort(DArray & myArray);



#endif



