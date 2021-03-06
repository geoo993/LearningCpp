//============================================================================
// Name        : RvaluesAndLvalues.cpp
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

Test getTest() {

	// c++ 98 does return value optimisation, which involves getting rid of extra copies of objects
	return Test();
}

int main() {

	Test test1(21, "Dan");

	Test test2 = test1;// this is called copy initialisation
	test2.print();
	test2.setName("alex");
	test2.setId(16);

	Test test3;

	test3 = test2;// this is called an assignment initialisation
	test3.print();

	Test test4 = getTest();// we are doing a copy initialisation
	cout << test4 << endl;// the ostream operator allows us to use the class object in the cout

	vector<Test> vec;
	vec.push_back(Test());


	//c++ 11 solves this copying of constructors problem by doing something called r value references, move constructors and move assignments operators
	// we always said that the R value is the value on the right and the L value is the value on the left
	int value1 = 7;//this is an r value because the value is to the right

	int *pValue1 = &value1;//in c++ 11, the L value is anything you can take the address of. so clearly here when the reference refers to value1, this becomes an L value meaning that pValue1 is a reference of value1 which makes it an L value
	//int *pValue2 = &7;// we cannot do this type of expression because 7 is an R value

	Test *pTest4 = &test4;// same here, pTest becomes as L value

	int *pValue2 = &++value1;// now we can also increment (prefix incrementation) the value when we are referencing it. this incrementation works becuase we are working with an L value
	cout << *pValue2 << endl;


	//int *pValue3 = &value1++;//this postfix incrementation will not work because there is a temporary value in there before the incrementation happens, meaning that the value within makes it an R value which coincide with the L value. so this will not work

	//int value4 = &(2 + value1); //here we know that adding value1 is an L value, but the 2 is the R value. so you cannot point to it with a pointer because the pointer will only reference and work an L value


	return 0;
}
