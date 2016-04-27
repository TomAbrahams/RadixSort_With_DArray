#include "RadixSort.h"


//This is to find the maximum number of digits needed to be used.
//Example if 1233 is max, then we need to find the item that has four digits.
int getMax(DArray myArray)
{
	int currentMax = myArray[0];
	for (int i = 0; i < myArray.getNumOfElements(); i++)
	{
		if (currentMax < myArray[i])
			currentMax = myArray[i];
	}
	return currentMax;
}
//Check get the digits
int getDigit(int theMax)
{
	int maxHolder = theMax;
	int numberOfDigits = 0;

	while (maxHolder != 0)
	{
		maxHolder /= 10;
		numberOfDigits++;
	}
	return numberOfDigits;
}
//Takes whole number converts it to the number in the digits place.
int nthDigit(int element, int digit)
{
	int divider = 1;
	//This gets me the appropriate modding tool
	for (int i = 1; i < digit; i++)
	{
		divider *= 10;
	}
	return ((element/divider) % 10);	
}
//Count Sort
void countSort(DArray & myArray, int exponent)
{
	//First divide by 10, if it is 0... Then ignore.
	DArray storedArray(myArray);
	//Clear the myArray to Sort
	storedArray.emptyArray();
	cout << "Here is the myArray:";
	myArray.printArray();
	cout << "Here is the storedArray:";
	storedArray.printArray();
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; (k < myArray.getNumOfElements()); k++)
		{
			cout << "Checking digit "<< i << " this " << myArray[k] << " converted=" << nthDigit(myArray[k], exponent) << "\n";
			if (nthDigit(myArray[k], exponent) == i)
			{		
				storedArray.addElement(myArray[k]);
			}
			storedArray.printArray();
		}
	}
	storedArray.printArray();
	/*
	for (int i = 0; i < myArray.getNumOfElements(); i++)
		myArray[i] = storedArray[i];
	*/
	cout << "Final Array:";
	myArray = storedArray;
	myArray.printArray();
}
//RadixSort
void radixSort(DArray & myArray)
{
	int theMax = getMax(myArray);
	int numberOfDigits = getDigit(theMax);
	for (int i = 1; i <= numberOfDigits; i++)
	{
		countSort(myArray, i);
	}
	cout << "Radixsort: ";
	myArray.printArray();
}
