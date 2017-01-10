//============================================================================
// Name        : DelegatingConstructors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent{
private:
	int id{2};
	string name = "Aio";

public:

	//in c++ 98 we could not call one constructor from another within a class, but c++ 11 allows us to do that
	//this process is called the delegate constructor

	Parent(): Parent(12, "Jon"){//using another constructor
		cout << "No Parameter Parent Constructor" << endl;
	}

	Parent(string name){
		this -> name = name;
		cout << "String Parameter Parent Constructor" << endl;
	}

	Parent(int id, string name): id(id), name(name){
		cout << "Int and String Parameter Parent Constructor" << endl;
	}

	void print(){
		cout << id << ": " << name << endl;
	}

	~Parent(){
		cout << "Destructor" << endl;
	}
};


class Child: public Parent{

public :
	Child() = default;// child is calling the default empty Parent constructor
};


int main() {


	Parent p;
	Child c;//when a child class is constructed it must run the supper class, unless you are doing polymorphism

	//in c++ 11 you can select what constructor you want to use
	c.print();


	return 0;
}
