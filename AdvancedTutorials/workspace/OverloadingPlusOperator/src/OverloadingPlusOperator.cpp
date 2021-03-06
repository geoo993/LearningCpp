//============================================================================
// Name        : OverloadingPlusOperator.cpp
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

	Complex c1(22.2, 30.4);

	Complex c2(123, 3.1);

	cout << c1 << endl;

	cout << endl;

	//to overload the plus operator, you either make a member function from the class or make an encapsulated free standing function
	Complex c3 = c1+c2;
	cout << c1+c2 << endl;

	cout << endl;

	Complex c4(12.5, 8.1);
	Complex c5 = c1+c3+c4;

	cout << c5 << endl;

	cout << endl;
	//overloading plus operator and passing values
	Complex c6(1.5,8.1);

	//now you can add the numbers from left or right of via plus operator overloading
	cout << c6+7 << endl;
	cout << 6+c6 << endl;
	cout << 6+c6+c1+5+c3+c4+2+29+20 << endl;


	cout << endl;
	//overloading minus operator and passing values
	Complex c7(5, 3.1);
	cout << c7 - 4 - 2 - 5.6 - 3.1 - c2 << endl;

	return 0;
}
