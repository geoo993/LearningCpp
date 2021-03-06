//============================================================================
// Name        : MoveAssignmentOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

class Test {
private:
	int id { 2 };
	string name = "Hello";

	static const int SIZE = 100;
	int *m_buffer{nullptr};

public:


	Test() //: Test(12, "Jon") //using another constructor
	{
		cout << "Constructor " << endl;
		m_buffer = new int[SIZE] { };

	}

	Test(string name) {

		cout << "Constructor with one Parameters" << endl;
		this -> name = name;

		m_buffer = new int[SIZE] { };

		for (int i = 0; i < SIZE; i++) {
			m_buffer[i] = 7 * i;
		}

	}

	Test(int id, string name) :
		id(id), name(name) {//parameters constructor

		cout << "Constructor with two Parameters" << endl;

		m_buffer = new int[SIZE] { };
	}

	Test(const Test &other) {//copy constructor

		cout << "Copy Constructor" << endl;
		m_buffer = new int[SIZE] { };

		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));

	}

	Test (Test &&other){ //this is a move copy constructor, usually you do not need const in R values references
		cout << "Move Copy Constructor" << endl;

		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;
	}


	Test &operator=(const Test &other)//assignment constructor
	{
		cout << "Assignment Constructor" << endl;
		m_buffer = new int[SIZE] { };

		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
		return *this;
	}

	Test &operator=(Test &&other){// this is the move assignment operator

		cout << "Move Assignment Constructor" << endl;

		delete [] m_buffer;
		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;

		return *this;
	}

	void setId(int id) {
		this -> id = id;
	}

	void setName(string name) {
		this -> name = name;
	}

	void print() {
		cout << id << ": " << name << endl;
	}

	~Test() {//destructor
		delete[] m_buffer;
		cout << "Destructor" << endl;
	}

	// the put to (<<) operator, so you can use objects of this class with cout
	friend ostream &operator<<(ostream &out, const Test &test);

};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test put to operator";
	return out;
}

//return values
Test getTest() {
	return Test();
}

void check(const Test &value){

	cout << "L value function." << endl;
}

void check(Test &&value){ // usually you do not need const in R values references

	cout << "R value function." << endl;
}



int main() {

	Test test1;

	check(test1);// L value of the function running
	cout << endl;

	check(Test());// R value of the function running
	cout << endl;

	check(getTest());// R value of the function running
	cout << endl;


	vector<Test> vec;
	vec.push_back(Test());// evoking move constructor

	cout << endl;

	test1 = getTest();// evoking move assignment constructor

	return 0;
}
