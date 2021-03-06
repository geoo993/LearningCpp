//============================================================================
// Name        : ConstKeyword.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Animal.h"
using namespace std;

int main() {

	int iValue = 5;
	iValue = 203;
	cout << "value can be changed -> "<< iValue << endl;


	const double PI = 3.142; // adding const on variable means that const is no longer a variable, it cannot be changed
	cout << "const value cannot be changed -> " << PI << endl;

	Animal anim1;
	anim1.setAnimal("Frog","amphibians group");
	anim1.print();

	Animal anim2;
	anim2.setAnimal("Pelican Falcon", "birds group");
	anim2.print();

	Animal anim3;
	anim3.setAnimal("Stone Fish", "fish group");
	anim3.print();

	Animal anim4;
	anim4.setAnimal("Worm","invertebrates group");
	anim4.print();

	Animal anim5;
	anim5.setAnimal("Giraffe", "mammals group");
	anim5.print();

	Animal anim6;
	anim6.setAnimal("Cobra", "reptiles group");
	anim6.print();


	int value = 82;
	int *pValue = &value;
	//const int *pValue = &value; // now here we are saying that the pointer should point to an int that is now constant.
	//int * const pValue = &value; // now here we are saying that the pointer is a constant and the int is not a constant any more.
	//const int * const pValue = &value; // now here we are saying that the pointer and the int that it is pointing to are constant.
	cout << "pointer value (pValue) points to value: " << *pValue << endl;

	int number = 11;
	pValue = &number;// can change where the pointer if referring to, but it will return an error if you change pValue to constant like this (int * const pValue = &value)
	cout << "pointer value (pValue) points to new number: " << *pValue << endl;

	*pValue = 33; // can also change the value of the pointer, but it will return an error if you change pValue to this (const int *pValue = &value)
	cout << "pointer value (pValue) has to assigned number: " << *pValue << endl;


	// you can also declare methods to be constants
	return 0;
}
