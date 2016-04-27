#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
public:
	DArray();

	DArray(int newCapacity);

	void addElement(int newElement);

	int getNumOfElements() const;

	void printArray() const;

	int & operator[](int i);
	

	/************************************************************/

	// Declaration function appendArray
	void appendArray(const DArray & appendArr);

	// Declaration copy constructor
	DArray(const DArray & copyArr);

	// Declaration overloaded assignment operator
	DArray & operator=(const DArray & eqArr);

	// Declaration function emptyArray
	void emptyArray();

	~DArray();

private:
	int *a;					//will point to an array of integers
	int capacity;			//capacity of the array
	int numOfElements;		//total number of elements in the array

};

#endif
