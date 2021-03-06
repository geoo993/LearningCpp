//============================================================================
// Name        : StringStreams.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>//this is the include string stream that allows you to concatenate other variable types to string
using namespace std;

int main() {

	string name = "Alex";
	int age = 32;

	stringstream ss;//string stream are basically stream of data, they are use to send data or get data from
	ss << "Name is : ";
	ss << name;
	ss << "; Age is: ";
	ss << age;

	string info = ss.str();
	cout << info << endl;//str() is from the string stream

	//can use (\n) for new line (\t) for tab (\") for quotation mark, all in string

	return 0;
}
