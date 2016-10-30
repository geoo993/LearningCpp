//============================================================================
// Name        : OverloadingTheDereferenceOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Complex.h"
using namespace std;
using namespace complexnumbering;

int main() {

	//here we are going to look at overloading the dereference operator (star or astros)
	Complex c1(3.2, 5.9);


	Complex c2(7.8, 9.6);

	cout << *c1 + 32 + *Complex(12.8, 44) + c2 << endl;
	cout << endl;


	Complex c3(4, 8.1);

	cout << c3*c1 << endl;


	return 0;
}
