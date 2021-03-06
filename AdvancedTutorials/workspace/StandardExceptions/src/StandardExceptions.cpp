//============================================================================
// Name        : StandardExceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//exceptions are also go for handling memory for case were the computer is unable to allocate memory for the object instances that you create.

class CanGoWrong{

public:
	CanGoWrong(){

		//char *pMemory = new char[999];// here we are allocating low memory


		// here we are allocating lots of memory which the computer cannot handle, so we need to create a exception for instances where the computer cannot allocate memory
		//if we did not have exception, we could not really allocate memory for these instances
		// so if you use exception, you can construct a mechanism for catching memory allocation exceptions like these
		char *pMemory = new char[999999999999999999];




		delete [] pMemory;
	}

};


int main() {

	try{
		CanGoWrong cgw;
	}
	catch(bad_alloc &e){
		cout << "Caught Exception Error: " << e.what() << endl;// what, lets you know what kind of exception it was
	}

	cout << "Still Running." << endl;

	return 0;
}
