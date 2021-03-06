//============================================================================
// Name        : LambdaExpressions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void test( void (*pFunc)() ){
	pFunc();
}

int main() {

	//you can use lambda expression to pass around functions
	//lambda expression looks alot like a bracket fest/party

	// we are defining a function that does not have a name
	[](){ cout << "Hello1" << endl; };// this is a valid lambda expression, this is kind of like an anonymous espression
	[](){ cout << "Hello2" << endl; }();// you put the round curly brackets at the end to call the function


	auto func = [](){ cout << "Hello World" << endl; };// now we have an anonymous function that has no name and we are storing the reference to that function in a variable
	func();//we call the anonymous function here

	test(func);//this is like a function pointer
	test([](){ cout << "Hello My Friend" << endl; });//you can specify the lambda expression directly

	return 0;
}
