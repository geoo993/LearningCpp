//============================================================================
// Name        : Pointers.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



//void manipulate(double value){
//
//	cout << "2. Value of double in manipulate " << value << endl;
//
//	value = 10.0;
//
//	cout << "3. Value of double in manipulate " << value << endl;
//}


void manipulate(double *pValue){//the type that we pass in here is a pointer to a double, meaning getting the reference to a double and being able to change it

	cout << "2. Value of double in manipulate " << *pValue << endl;

	*pValue = 10.0;// this says change the value that this pointer is referencing to

	cout << "3. Value of double in manipulate " << *pValue << endl;
}


int main() {

	int nValue  = 16;// here we allocated some memory, we can think of this as a bucket, we put something in the bucket which now has a view or size

	int *pnValue = &nValue;// you can create a variable that stores the address of variables like the nValue int for example, to do that you create an int pointer (int *) that takes the address of the variable in this case the nValue int
	// here we are saying here pointer (int *) to an int (pnValue) equals to the address of nValue
	//pnValue stored the address of the nValue int.
	//pnValue is essentially the memory location of the nValue int


	cout << "Int value: " << nValue << endl;
	cout << "Pointer to int address: " << pnValue << endl;


	// you can dereference the pointer by just typing * in front of the pointer variable and this will give the value that the pointer refers to
	cout << "Int value via Pointer: " << *pnValue << endl;



	cout << endl << "================" << endl << endl;

	//pointers contain addresses of values/variables

	double dValue = 123.45;
	cout << "1. dValue: " << dValue << endl;
	manipulate(&dValue);
	cout << "4. dValue after manipulate: " << dValue << endl;

	return 0;

}
