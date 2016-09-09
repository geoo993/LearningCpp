//============================================================================
// Name        : ConstructorParametersAndOverloading.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tvs.h"
using namespace std;

int main() {

	Tvs tvs;
	tvs.setName("Sony TV");

	Tvs tvs2("Samsung", "55 Inch", 2500.99);// can set parameters in constructor

	cout << tvs.print() << endl;

	cout << endl << tvs2.print() << endl;
	return 0;
}
