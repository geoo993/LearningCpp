//============================================================================
// Name        : CustomExceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>// adding exception header will allow you to use exception code or library

using namespace std;

//inherit from c++ exception
class MyException: public exception {

public:

	//the const throw() means that the function cannot throw an exception
	//however, what it will do is cause the program to halt at run time
	virtual const char* what() const throw()
	{
		return "Something really bad Happened!";
	}

	//you can choice the type of throw you want your method to be able show
	const char * print() const throw(bad_exception, bad_alloc, runtime_error) {
		return "Printing something that is really bad!";
	}
};


class Test{

public:

	Test(){}
	void goesWrong(){
		throw MyException();
	}
};


int main() {

	Test test;

	try{
		test.goesWrong();
	}catch(MyException &e){
		cout << "Exception Error message: " << e.what() << endl;
		cout << "Exception Error message: " << e.print() << endl;
	}
	return 0;
}
