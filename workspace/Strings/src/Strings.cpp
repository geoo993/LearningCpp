//============================================================================
// Name        : Strings.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {



	int value = 6;//value is an object, string is technically a class and int is a primitive type


	string text1 = "this is a string called: ";//strings are one the things that are not standard between compilers
	string text2 = "Alex";//strings is not a cpp keyword which is why its not highlighted like the other primitive types like int, this is because it was added after, maybe as a components on top of the other cpp keywords

	string text3 = text1+text2; //concatonating one string with another

	cout << text3 << endl;
	cout << text1 << text2 << value << endl;

	return 0;
}
