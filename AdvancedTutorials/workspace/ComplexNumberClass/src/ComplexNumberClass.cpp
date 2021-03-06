//============================================================================
// Name        : ComplexNumberClass.cpp
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


	//we can use complex number class to overload operators
	//complex numbers have a real and imaginary part

	Complex c1(2.3, 5.7);

	Complex c2(c1);

	Complex c3(23, 42.3);
	c1 = c3;

	cout << c1 << c2 << c3 << endl;

	return 0;
}
