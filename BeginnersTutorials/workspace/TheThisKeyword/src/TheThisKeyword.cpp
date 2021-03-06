//============================================================================
// Name        : TheThisKeyword.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Fruit.h"
using namespace std;

int main() {

	Fruit fruit1("Apple", "Green");
	Fruit fruit2("Banana", "Yellow");

	cout << fruit1.toString() << "; Memory location of fruit1 " << &fruit1 << endl;// to get the actual memory location of an object in cpp, you just preface it with an and (&). This is a way of getting a memory address of an object
	cout << fruit2.toString() << "; Memory location of fruit2 " << &fruit2 << endl;
	return 0;
}
