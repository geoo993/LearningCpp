//============================================================================
// Name        : RValueReferences.cpp
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

//return values
Test getTest(){
	return Test();
}

void check(const Test &value){

	cout << "L value function." << endl;
}

void check(Test &&value){ // usually you do not need const in R values references

	cout << "R value function." << endl;
}


int main() {

	Test test1 = getTest();

	vector<Test> vec;
	vec.push_back(Test());

	//binding L and R Value references via const
	const Test &rTest = getTest();
	cout << rTest << endl;

	Test test2(Test(6, "Fred"));//passing temporary values

	//if we could identify temporary values somehow, we could handle them to how we handle non temporary values and potentially introduce optimisation in our code. and thats what R Values references are for
	Test &lTest = test1;//L value reference
	cout << lTest << endl;

	Test &&rTest1 = Test()/*test1*/;  //R value reference, the double ampersand has a new meaning, we cannot bind an R value reference to an L value reference directly
	Test &&rTest2 = getTest();

	cout << rTest1 << "  " << rTest2 << endl;
	//so R value references give us a way to differentiate between temporary values and non temporary values, or more precisely between L values and R values

	check(test1);// L value of the function running
	check(Test());// R value of the function running
	check(getTest());// R value of the function running

	//so you can use this R value references to move constructors and more assignment operators, which proves to be a lot more efficient than copy constructors

	return 0;
}
