//============================================================================
// Name        : DataMembers.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cat.h"
using namespace std;

int main() {

	Cat lina;
	lina.makeCatHappy();
	cout << lina.noise() << endl;


	Cat max;
	max.makeCatSad();
	cout << max.noise() << endl;

	return 0;
}
