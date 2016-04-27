/*
Abrahams, Thomas
CS A200
April 7, 2016

This program creates partially-filled
arrays of integers.


*/

#include "DArray.h"
#include "RadixSort.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "CLASS DARRAY\n\n";

	cout << "Append arrays with different number of elements...\n";
	DArray arr1(10);
	arr1.addElement(10);
	arr1.addElement(11);
	arr1.addElement(12);
	arr1.addElement(13);
	arr1.addElement(14);
	DArray arr2(30);
	arr2.addElement(20);
	arr2.addElement(21);
	arr2.addElement(22);
	arr2.addElement(23);
	cout << "arr1: ";
	arr1.printArray();
	cout << "arr2: ";
	arr2.printArray();
	arr1.appendArray(arr2);
	cout << "arr1 is now: ";
	arr1.printArray();

	cout << "\nAppend arrays with second array empty...\n";
	DArray arr3(15);
	arr3.addElement(10);
	arr3.addElement(11);
	arr3.addElement(12);
	arr3.addElement(13);
	arr3.addElement(14);
	cout << "arr3: ";
	arr3.printArray();
	DArray arr4(20);
	cout << "arr4: ";
	arr4.printArray();
	arr3.appendArray(arr4);
	cout << "arr3 is now: ";
	arr3.printArray();

	cout << "\nAppend arrays with first array empty...\n";
	DArray arr5(10);
	cout << "arr5: ";
	arr5.printArray();
	DArray arr6(20);
	arr6.addElement(10);
	arr6.addElement(11);
	arr6.addElement(12);
	arr6.addElement(13);
	arr6.addElement(14);
	arr6.addElement(15);
	cout << "arr6: ";
	arr6.printArray();
	arr5.appendArray(arr6);
	cout << "arr5 is now: ";
	arr5.printArray();

	cout << "\nTry and append arrays with not enough space...\n";
	DArray arr7(10);
	arr7.addElement(10);
	arr7.addElement(11);
	arr7.addElement(12);
	arr7.addElement(13);
	arr7.addElement(14);
	arr7.addElement(15);
	arr7.addElement(16);
	cout << "arr7: ";
	arr7.printArray();
	DArray arr8(20);
	arr8.addElement(20);
	arr8.addElement(21);
	arr8.addElement(22);
	arr8.addElement(23);
	cout << "arr8: ";
	arr8.printArray();
	arr7.appendArray(arr8);
	cout << "arr7 is now: ";
	arr7.printArray();

	cout << "New Tests\n";
	DArray testArr1;
	cout << "testArr1:";
	testArr1.printArray();
	cout << "Test Overloaded Assignment Operator\n";
	cout << "arr7 is : ";
	arr7.printArray();
	testArr1 = arr7;
	cout << "testArr1 = arr7" << endl;
	cout << "testArr1:";
	testArr1.printArray();
	cout << endl;
	//Test Copy Constructor
	DArray testArr2(testArr1);
	cout << "Testing copy constructor" << endl;
	cout << "testArr1 is :";
	testArr1.printArray();
	cout << "DArray testArr2(testArr1)\n";
	cout << "testArr2 is :";
	testArr2.printArray();



	system("Pause");
	
	cout << "Testing Radix Sort\n";
	DArray theTester(20);
	theTester.addElement(1);
	theTester.addElement(1002);
	theTester.addElement(2332);
	theTester.addElement(233);
	theTester.addElement(234214239);
	theTester.addElement(7772);
	theTester.addElement(3238);
	theTester.printArray();
	cout << "The Radix Sort Attempt.\n";
	radixSort(theTester);
	theTester.printArray();
	system("pause");

	return 0;
}

