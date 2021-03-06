//============================================================================
// Name        : ConstructorsAndMemory.cpp
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
	int *m_buffer;

public:

	Test() :
		Test(12, "Jon") {//using another constructor

		cout << "No Parameters in Constructor" << endl;


		//m_buffer = new int[SIZE];

		//type 1
		//memset(m_buffer, 0, sizeof(int)*SIZE);//setting the individual bites in this buffer to zero, so we are setting all the bites of this int to zero

		//type 2
		m_buffer = new int[SIZE]{};//another way to empty all the bites in this buffer is to add an empty curly brackets {}, it will zero all the bites in this buffer


	}

	Test(string name) {

		cout << "String Parameter in Constructor" << endl;

		this -> name = name;

		m_buffer = new int[SIZE]{};

		for (int i=0; i<SIZE;i++){
			m_buffer[i] = 7*i;
		}

	}

	Test(int id, string name) :
		id(id), name(name) {//parameters constructor

		m_buffer = new int[SIZE]{};

		cout << "Int and String Parameter in Constructor" << endl;
	}

	Test(const Test &other)// copy constructor
	{
		cout << "Copy Constructor" << endl;

		m_buffer = new int[SIZE]{};

		memcpy(m_buffer, other.m_buffer, SIZE*sizeof(int));

	}

	Test &operator=(const Test &other)//assignment constructor
	{
		cout << "Assignment Constructor" << endl;

		m_buffer = new int[SIZE]{};

		memcpy(m_buffer, other.m_buffer, SIZE*sizeof(int));

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
		delete [] m_buffer;
		cout << "Destructor" << endl;
	}

	// the put to (<<) operator, so you can use objects of this class with cout
	friend ostream &operator<<(ostream &out, const Test &test);

};

ostream &operator<<(ostream &out, const Test &test) {
	out << "Hello from test put to operator";
	return out;
}

Test getTest() {

	// c++ 98 does return value optimisation, which involves getting rid of extra copies of objects
	return Test();
}

int main() {

	Test test4 = getTest();// we are doing a copy initialisation
	cout << test4 << endl;// the ostream operator allows us to use the class object in the cout

	vector<Test> vec;
	vec.push_back(Test());


	return 0;
}
