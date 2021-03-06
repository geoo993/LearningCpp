//============================================================================
// Name        : PerfectForwarding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Test {
private:
	int id { 2 };
	string name = "Aio";

public:

	Test() {

		cout << "Constructor..." << endl;
	}

	Test(int id, string name) :
		id(id), name(name) {//parameters constructor

		cout << "Parameter in Constructor" << endl;
	}

	Test(const Test &other)// copy constructor
	{
		cout << "Copy Constructor" << endl;
		this -> id = other.id;
		this -> name = other.name;
	}

	Test &operator=(const Test &other)//assignment constructor
	{
		cout << "Assignment Constructor" << endl;

		this -> id = other.id;
		this -> name = other.name;

		return *this;

	}

	void print(){
		cout << id << ": " << name << endl;
	}
	~Test() {

		cout << "Destructor..." << endl;
	}


};


Test getTest(){
	return Test();
}

void check(const Test &value){

	cout << "L value function." << endl;
}

void check(Test &&value){

	cout << "R value function." << endl;
}


template<typename T>
void call(T &&arg){
	//the idea behind perfect forwarding is that you might want to call the right version of the check function here depending on if you passed an L or R value in the template type. so in this function you would pass either an R or L value type with the T template. we are going to end up with a type T being inferred that it just makes the function work
	//then we might want to pass on the argument in such a way that the L or R value references are preserved
	//check(static_cast<T>(arg));// static cast allows us to pass and use arg, checking it so it gives us the right check type
	check(forward<T>(arg));//forward does the same thing, it passes the arg value in a forwarding way, similarly to static_cast
}


int main() {

	Test test;
	cout << endl;

	check(test);// L value of the function running
	check(Test());// R value of the function running
	check(getTest());// R value of the function running

	auto &&t1 = Test();//R value reference
	auto &&t2 = test;//T here cannot be an R value reference, because this will not work on L value references. this works because there is a rule on auto that says that when auto boils down to an L value reference type then the references as a whole will collapse and we will be left with an L value reference which is why this binds to an L value

	t1.print();
	t2.print();

	cout << endl;

	//using perfect forwarding that return a check function
	call(Test());//template declaration that use R values
	call(test);////template declaration that use L values


	return 0;
}
