//============================================================================
// Name        : UniquePointer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>//if you want to use any kind of smart pointer you have to include this
using namespace std;


//unique pointer are kind of smart pointer, behaves like normal pointer except they handle the deallocation of memory for you
//memory leaks are a common problem in c++ program because you do not get enough deletes being called or the right type of deletes for the object you've allocated with new and smart pointer are the one that can help to handle deallocation of memory and avoiding those bugs
class Test {
public:
	Test(){
		cout << "Constructor to create" << endl;
	}

	void print(){
		cout << "Hello World!" << endl;
	}


	~Test(){
		cout << "Destructor to destroy" << endl;
	}
};


class Temp{
private:
	unique_ptr<Test[]> pTest;
public:
	Temp() : pTest(new Test[3])
	{

	}


};

int main() {

	//unique_ptr is the smart pointer, which is a template type
	//unique_ptr knows that it is a pointer, it just needs the type that it is going to point at
	//to make use of this smart pointer unique_ptr, you have to include memory header
	unique_ptr<int> pInt(new int);// you have to do the memory allocation by passing the value of the pointer
	*pInt = 9;//here we are dereferencing the pointer and the smart pointer will deallocate the memory we allocated
	cout << *pInt << endl;
	cout << endl;

	//using brackets to keep the element within a scope
	{
		//Test *pTest1;//normal pointer but the memory is not deallocated
		//pTest1->print();

		cout << endl;

		//this test with smart pointer shows how the memory is deallocated
		unique_ptr<Test> pTest(new Test);//here we are allocating memory, this works just like a normal pointer
		pTest->print();

		cout << endl;

		unique_ptr<Test[]> pTestArray(new Test[3]);
		pTestArray[2].print();

	}

	{
		cout << endl;
		Temp temp;// here we no longer need to have a destructor to deallocate memory of member elements or variables in classes
	}

	cout << endl;
	cout << "Finished" << endl;

	return 0;
}
