//============================================================================
// Name        : AutoKeyword.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


auto test1() -> int//Trailing return type
{
	return 7;
}


// for the return type of a function that uses auto, you got to have a trailing type, such as decltype
template <class T>
auto test2(T value) -> decltype(value)
{
	return value;
}

template <class T, class C>
auto test3(T value1, C value2) -> decltype(value1+value2) // you can use expressions with decltype
{
	return value1 + value2;
}


int get(){
	return 999;
}

auto test4() -> decltype(get())
{
	return get();
}

int main() {

	//auto is the default storage class or type specifier, you normally don't need to type it out explicitly
	//when declaring a variable, you can actually miss out the type and replace it with auto, c++ will try to figure out the type for you

	//c++ will figure out for it self what the type of this variable is
	//auto value = 7;
	//auto value = 7.2;
	auto value = "she";
	cout << value << endl;

	//you can also use auto for the return type of functions
	cout << "Test1: "<< test1() << endl;

	cout << "Test2: " << test2(3) << endl;

	cout << "Test3: " << test3(3, 9) << endl;
	cout << "Test3: " << test3(4.7, 9.4) << endl;
	cout << "Test3: " << test3('G', 'Q') << endl;

	cout << "Test4: " << test4() << endl;


	return 0;
}
