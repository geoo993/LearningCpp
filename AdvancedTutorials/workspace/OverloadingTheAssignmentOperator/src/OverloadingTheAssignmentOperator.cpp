//============================================================================
// Name        : OverloadingTheAssignmentOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
private:
	int id;
	string name;

public:

	Test() :
		id(0), name("") {
	}

	//copy constructor
	Test(const Test &other) {

		cout << "Copy Constructor running" << endl;

//		id = other.id;
//		name = other.name;

		*this = other;// you can use this instead of the above assignments

	}

	Test(int id, string name) :
		id(id), name(name) {
	}

	~Test() {
		//cout << "Destroyed Object" << endl;
	}

	void print() const {
		cout << name << ": " << id << endl;
	}

	//creating a binary operator, for operator you use the operator key word
	const Test &operator=(const Test &other) {

		cout << "Assignment running" << endl;
		id = other.id;
		name = other.name;

		return *this;
	}

};


int main() {

	Test test1(12, "Mike");
	cout << "Print test1: " << flush;
	test1.print();

	cout << endl;

	//c++ provides a default implementation of something that causes an object to be overridden by another object just like we see here
	Test test2(31, "Bob");
	test2 = test1;// this is called copy initialisation
	cout << "Print test2: " << flush;
	test2.print();

	cout << endl;

	Test test3(29, "Alex");
	//test3 = test2 = test1;//this is like method chaining
	test3.operator=(test2);//this is equivalent to (test3 = test2)
	cout << "Print test3: " << flush;
	test2.print();

	cout << endl;

	Test test4 = test1;// this is called copy initialisation, this happens when you create an object and not giving it initial values and then make it copy another other object, so it will use the copy constructor from the class
	test4.print();

	//sometimes its best to override rather than doing a shallow copy of an object and to do that by overriding the operator, creating a binary operator in the class
	test4.operator=(test3);
	test4.print();

	return 0;
}

