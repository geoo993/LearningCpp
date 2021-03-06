//============================================================================
// Name        : References.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//pointer references allow you to point and reference to a variable initialized outside if a function or method. it help you save memory and stops you from creating copies of those variable but instsead helping to point to an earlier variable.

double changeSomethingWithReturn (double dValue){
	dValue = 4.5934;
	return dValue;
}

void changeSomethingWithReferencing (double &dValue){ //adding & allows to change the value passed in the function, almost like a return function
	dValue = 4.5934;
}

int main() {

	int val1 = 8;
	int val2 = val1; //this says that value 2 is a reference of value 1
	val2 = 23;
	cout << "value1: " << val1 << endl;
	cout << "value2: " << val2 << endl;

	cout << endl;

	int val3 = 11;
	int &val4 = val3; //here, we are de-referencing value 3 with &, which makes value3 to be changed when value4 changes, &val4 means that its just another name of val3 mainly because we added (&) in front, so what ever we do with val4 is going to happen with val3

	val4 = 20;

	cout << "value3: " << val3 << endl;
	cout << "value4: " << val4 << endl;



	double dVal = 9.876;
	changeSomethingWithReferencing(dVal);
	cout << dVal << endl;

	cout << changeSomethingWithReturn(dVal) << endl;


	return 0;
}
