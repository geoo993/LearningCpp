//============================================================================
// Name        : UsingNamespaces.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cat.h"
using namespace std;// using namespace standard
using namespace cats;

// namespaces are a way of avoiding conflict between classes or variables or even global variables that have the same name
int main() {

	Cat cat;
	cat.print();

	return 0;
}
