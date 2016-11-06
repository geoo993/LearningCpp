//============================================================================
// Name        : DecltypeAndTypeid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>//type id is a keyword and you need to include this to use it

using namespace std;


int main() {

	int value1;
	float value2;
	double value3;
	string value4;
	char value5;

	// this is going to give us a type information
	// type id gives us type information of variables
	cout << typeid(value5).name()  << endl;


	//decltype is another kind of like sizeof or typeid
	//decltype allows us to declare variable of an existing type
	//we can also use it to form a return type of a function
	decltype(value4) name = "Bob";//this is like typing a string

	cout << typeid(name).name()  << endl;
	cout << name  << endl;

	return 0;
}
