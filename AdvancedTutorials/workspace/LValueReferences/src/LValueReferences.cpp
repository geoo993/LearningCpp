//============================================================================
// Name        : LValueReferences.cpp
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
	string name = "Aio";

	static const int SIZE = 100;
	int *m_buffer{nullptr};

public:

	Test() :
		Test(12, "Jon") {//using another constructor

		cout << "No Parameters in Constructor" << endl;

		//m_buffer = new int[SIZE];

		//type 1
		//memset(m_buffer, 0, sizeof(int)*SIZE);//setting the individual bites in this buffer to zero, so we are setting all the bites of this int to zero

		//type 2
		m_buffer = new int[SIZE] { };//another way to empty all the bites in this buffer is to add an empty curly brackets {}, it will zero all the bites in this buffer


	}

	Test(string name) {

		cout << "String Parameter in Constructor" << endl;

		this -> name = name;

		m_buffer = new int[SIZE] { };

		for (int i = 0; i < SIZE; i++) {
			m_buffer[i] = 7 * i;
		}

	}

	Test(int id, string name) :
		id(id), name(name) {//parameters constructor

		m_buffer = new int[SIZE] { };

		cout << "Int and String Parameter in Constructor" << endl;
	}

	Test(const Test &other)// copy constructor
	{
		cout << "Copy Constructor" << endl;

		m_buffer = new int[SIZE] { };

		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));

	}

	Test &operator=(const Test &other)//assignment constructor
	{
		cout << "Assignment Constructor" << endl;

		m_buffer = new int[SIZE] { };

		memcpy(m_buffer, other.m_buffer, SIZE * sizeof(int));
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

Test getTest(){
	return Test();
}

int main() {

	Test test1 = getTest();
	cout << test1 << endl;

	vector <Test> vec;
	vec.push_back(Test());

	//in c++ 98, we have references, which in c++ 11 we now call specifically L value references because c++ 11 introduces R value references
	//so an L value reference is the normal kind of referencing
	Test &rTest1 = test1;// this is a normal reference, here we can have a reference to test1, meaning L value referencing. this L value referencing shows how you can only bind values the same way as c++ 98 by referencing to another object
	cout << rTest1 << endl;

	//if we try to bind an R Value reference to an L value reference, it will not work
	//Test &rTest2 = getTest();//this R value referencing cannot work

	const Test &rTest2 = getTest();// this is the only case that you can bind R and L value references because const L values references can in-fact bind to R values
	cout << rTest2 << endl;

	Test test2(Test(6, "Fred"));


	return 0;
}
