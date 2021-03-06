//============================================================================
// Name        : OverloadingComparisonOperator.cpp
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

	Complex c1(12, 6);

	Complex c2(23, 7.1);
	Complex c3(12, 6);

	cout << c1 << endl;

	if (c1 == c2){
		cout << "They are equal" << endl;
	}else{
		cout << "They are not equal" << endl;
	}

	if(c1.getReal() != 2.1){
		cout << "Not equal" << endl;
	}else{
		cout << "Equal" << endl;
	}

	cout << comp(c1, c2) << endl;

	cout << endl;
	return 0;
}
