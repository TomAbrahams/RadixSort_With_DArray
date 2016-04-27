#include "DArray.h"

DArray::DArray()
{
	capacity = 50;
	a = new int[capacity];
	numOfElements = 0;
}

DArray::DArray(int newCapacity)
{
	capacity = newCapacity;
	a = new int[capacity];
	numOfElements = 0;
}

void DArray::addElement(int newElement)
{
	if (numOfElements >= capacity)
	{
		cerr << "Attempt to exceed capacity in DArray.\n";
		exit(0);
	}
	else
	{
		a[numOfElements] = newElement;
		++numOfElements;
	}
}

int DArray::getNumOfElements() const
{
	return numOfElements;
}

void DArray::printArray() const
{
	if (numOfElements == 0)
		cerr << "Array is empty." << endl;
	else
	{
		for (int i = 0; i < numOfElements; ++i)
			cout << a[i] << " ";
		cout << endl;
	}
}

DArray::~DArray()
{
	delete[] a; //delete the array
	a = NULL;	 //null the pointer (not necessary, but good practice)
}

/************************************************************/

// Definition function appendArray
void DArray::appendArray(const DArray & appendArr)
{
	//If there are no elements to copy do not proceed
	if (appendArr.numOfElements != 0)
	{
		if (appendArr.numOfElements + numOfElements > capacity)
			cerr << "Not enough space to append elements." << endl;
		else
			for (unsigned int i = 0; i < appendArr.numOfElements; i++)
			{
			if (numOfElements >= capacity)
			{
				cerr << "Attempt to exceed capacity in DArray.\n";
				exit(0);
			}
			else
			{
				a[numOfElements] = appendArr.a[i];
				++numOfElements;
			}
			}
	}

}

// Definition copy constructor
DArray::DArray(const DArray & copyArr)
{
	capacity = copyArr.capacity;
	a = new int[copyArr.capacity];
	numOfElements = 0;
	for (unsigned int i = 0; i < copyArr.numOfElements; i++)
	{
		a[numOfElements] = copyArr.a[i];
		++numOfElements;
	}
}


// Definition overloaded assignment operator
DArray & DArray::operator=(const DArray & eqArr)
{
	if (this == &eqArr)
		cerr << "Cannot assign to itself" << endl;
	else if (capacity != eqArr.capacity)
	{
		delete[] a; //delete the array
		a = NULL;	 //null the pointer (not necessary, but good practice)
		a = new int[eqArr.capacity];
		//Reset number of elements. This is due to the elements
		numOfElements = 0;
		for (unsigned int i = 0; i < eqArr.numOfElements; i++)\
		{
			a[numOfElements] = eqArr.a[i];
			++numOfElements;
		}
	}
	else if (capacity == eqArr.capacity)
	{
		//Reset number of elements. This is due to the elements
		numOfElements = 0;
		for (unsigned int i = 0; i < eqArr.numOfElements; i++)
		{
			a[numOfElements] = eqArr.a[i];
			++numOfElements;
		}
	}
	return *this;
}

// Definition function emptyArray
void DArray::emptyArray()
{
	numOfElements = 0;
}

int & DArray::operator[](int i)
{
	if (i > numOfElements)
	{
		cerr << "Index is out of bounds\n";
		return a[0];
	}
	else
		return a[i];
}
