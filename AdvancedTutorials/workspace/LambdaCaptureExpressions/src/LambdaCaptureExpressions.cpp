//============================================================================
// Name        : LambdaCaptureExpressions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	int five = 5;

	//if you think of a lambda expression that does not have a name.
	//there is no return type because the return type is usually inferred, but you can use trailing return type if you need to specify a retrun
	[](){}();//bracket fest, useless expression

	//[](){ cout << one << endl; }();//lambda expressions have their own scope, you cannot pass in other variables

	//the first square brackets allows you to capture local variables, you do it to pass in the values you want to use in the lambda expression
	[one, two](){ cout << one << ", " << two << endl; }();

	//the [=] means capture all local variables by values
	[=](){ cout << one << ", " << two << ", " << three << ", " << four << endl; }();

	// you can also capture variable by reference (&) and values the [=]
	//so the default capture here is that it captures all variables by values [=] and but will capture four by reference
	[=, &four](){ four = 36; cout << one << ", " << two << ", " << three << ", " << four << endl; }();

	cout << four << endl;

	//capture all local variables by reference
	[&](){ cout << one << ", " << two << ", " << three << ", " << four << endl; }();

	//capture all local variables by reference and capture (one and two) by value
	[&, one, two](){ three = 33; four = 4; five = 55; cout << one << ", " << two << ", " << three << ", " << four << ", " << five << endl; }();

	return 0;
}
