//============================================================================
// Name        : MutableLambdas.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {


	int originalValue = 0;
	int value = 0;

	//mutable keyword
	[value, &originalValue]() mutable
	{

		// by default the lambda expression does not allow you to assign to external local variables
		//value = 4;

		//but if you put the keyword mutable into the lambda expression, after the round brackets, it will allow you to do so
		value = 44;// but bear in mind your not changing the value, becuase you are making a copy of the value in side the lambda expression, so if you wanted to change the local variable you will need to reference to it

		originalValue = value;

		cout << value << endl;


	}();

	value = originalValue;
	cout << value << endl;


	return 0;
}
