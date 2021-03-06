//============================================================================
// Name        : SharedPointer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
	Test(){
		cout << "Constructor" << endl;
	}

	void print(){
		cout << "Hello World!" << endl;
	}


	~Test(){
		cout << "Destructor" << endl;
	}
};


//shared pointers are really similar to unique pointer but just have little twist to them
//shared pointers dont delete the memory associated with your objects until all the other pointers that points at that object have been used and gone out of scope
//you cannot used shared pointers to point at arrays like unique pointers

int main() {

	//the best way to create and use a shared pointer is use a make shared macro
	shared_ptr<Test> pTest3(nullptr);

	{
		shared_ptr<Test> pTest1(new Test);
		pTest1->print();

		cout << endl;
	}

	{

		cout << endl;

		shared_ptr<Test> pTest2 = make_shared<Test>();

		pTest3 = pTest2;

		cout << endl;

		auto pTest4 = pTest2; //here, pTest4 will not work because pTest2 has been dealocated when it was assigned on pTest3
	}


	cout << "Finished" << endl;

	cout << endl;

	return 0;
}
