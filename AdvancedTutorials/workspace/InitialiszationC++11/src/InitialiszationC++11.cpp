//============================================================================
// Name        : InitialiszationC++11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	// c++ generalises the usage of braces
	int value{5};// here you do not need to put the equal sign
	cout << value << endl;

	string text{"Hello World!"};
	cout << text << endl;


	int numbers[]{1,2,3,4,5,6};
	cout << numbers[5] << endl;

	int numbers1[5]{};//we initialised all 5 elements to zero
	cout << numbers1[2] << endl;

	int *pInts = new int[4]{1, 2, 34, 6};
	cout << pInts[2] << endl;
	//delete pInts;


	int value1{};// here we initialise to default value, which is zero
	cout << value1 << endl;

	double value2{};

	double *pSomething{&value2};// can also use pointer
	cout << pSomething << endl;//show address
	cout << *pSomething << endl;//show value value

	//NULL is like a macro, it will initialise elements to their default values
	//however NULL is not a c++ keyword, its comes from C language
	float value3{NULL};
	cout << value3 << endl;

	//c++ 11 introduced the nullptr type, which you can use specificatly when initialising pointers
	int *value4{nullptr};// the nullptr is like true or false keyword, you cannot use it to cast values
	//int *value4{};// this is equivalent to (  int *value4{nullptr};  )
	cout << value4 << endl;



	struct S {
		string text;
		int id;
	} s1 {"Hello", 4}, s2 {"Hi There", 23};

	cout << s1.text << ", " << s2.text << endl;

	//new way of initialising and adding elements to vectors
	vector<string> strings {"one", "two", "three"};
	cout << strings[2] << endl;

	return 0;
}
