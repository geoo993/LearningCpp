//============================================================================
// Name        : ObjectInitializatioDeleteDefault.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Test{

private:
	int id{3};
	string name{"Kei"};

public:


//	Test(){
//
//	}
	Test() = default;// now you can simply set the constructor to default without having to put the curly brackets

	Test(const Test &other) = default;//copy constructor will automatically set the values to copy using this default
	//Test(const Test &other) = delete;//copy constructor will be deleted, so it will not be available


	Test &operator=(const Test &other) = default;//assigment operator to default
	//Test &operator=(const Test &other) = delete;//assigment operator now deleted, so it wont work


	Test(int id): id(id)//now you dont need to do all these initialisations
	{
	}
	Test(int id, string name): id(id), name(name){};//now you do not need to do all these initialisations


	void print(){
		cout << id << ": "<< name << endl;

	}
};


int main() {


	Test test;
	test.print();


	Test test1(66);// now you can override the default or the initialisation value set in the class
	test1.print();


	Test test2 = test1;
	test2.print();


	Test test3(30, "Hello");
	Test test4(56);
	test4.print();

	test4 = test3;
	test4.print();

	return 0;
}
