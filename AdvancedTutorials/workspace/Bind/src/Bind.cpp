//============================================================================
// Name        : Bind.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;


int add(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
	return a + b + c;
}

void run(function<int(int, int)> func) {

	cout << func(34, 68) << endl;
}


class Test {

public:
	int adding(int a, int b, int c, int d) {
		cout << a << ", " << b << ", " << c << ", " << d << endl;
		return a + b + c + d;
	}
};

int main() {

	//bind is supported natively in c++ 11 and bind allows us to create kind of aliases (also known as, aka) to functions, a bit like function pointers
	//you need to include functional header to use bind
	cout << add(1, 2, 3) << endl;

	auto calculate = bind(add, 3, 2, 8);//here we binded is the add function and give it its arguments using bind, now every time we all this calculate its going to put together those arguments
	cout << calculate() << endl;//calculate is going to behave like the add function due to the bind

	auto calculateWithPlaceholders = bind(add, _1, _2, _3);//using placeholders allows you to set or arrange the order in which the values are added in the argument list, meaning you can set placeholders and then add the values you need inserted later on.
	int result = calculateWithPlaceholders(2, 4, 12);//Assigning the values to the bind after using placeholder in the argument list
	cout << result << endl;

	//you can also combine placeholders with the arguments list, you change the order of the placeholders, re-arrange them, and also mix them with over values
	auto calculateMixingPlaceholders1 = bind(add, _3, 100, 28);
	auto calculateMixingPlaceholders2 = bind(add, _1, _3, 25);
	cout << calculateMixingPlaceholders1(0, 0, 45) << endl;
	cout << calculateMixingPlaceholders2(22, 0, 5) << endl;

	//mixing using the run function
	run(bind(add, _1, 3, _2));
	run(bind(add, _2, _1, 20));
	run(bind(add, 49, _1, _2));

	// a common thing to do is to bind using methods
	//we can bind with a method doing this, getting the method in the class
	Test test;
	auto calculateBindMethod = bind(&Test::adding, test, 20, 100, 30, 50);
	cout << calculateBindMethod() << endl;
	run(bind(&Test::adding, test, 42, _1, _2, 80));

	return 0;
}
