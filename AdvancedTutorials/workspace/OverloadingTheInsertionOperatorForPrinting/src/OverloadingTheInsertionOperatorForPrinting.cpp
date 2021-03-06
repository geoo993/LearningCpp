//============================================================================
// Name        : OverloadingTheInsertionOperatorForPrinting.cpp
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

	Test(const Test &other) {
		*this = other;
	}

	Test(int id, string name) :
		id(id), name(name) {
	}

	~Test() {
	}

	const Test &operator=(const Test &other) {

		cout << "Assignment running" << endl;
		id = other.id;
		name = other.name;

		return *this;
	}

	int getId() const {
		return id;
	}

	string getName() const {
		return name;
	}

	friend ostream &operator<<(ostream &out, const Test &test);

};

ostream &operator<<(ostream &out, const Test &test) {
	//out << test.id << ": " << test.name;
	out << test.getId() << ": " << test.getName();
	return out;
}

int main() {

	Test test1(23, "Mike");
	Test test2(43, "Bob");
	//cout is type of ostream
	//some opertors in c++ are right left associatives of left and right
	//to make this work you have to make test1 into an ostream becuase cout is an ostream
	//so we need to create an overloaded function on (cout << test1)
	cout << test1 << endl;

	cout << test2 << ", " << test1 << endl;


	return 0;
}
