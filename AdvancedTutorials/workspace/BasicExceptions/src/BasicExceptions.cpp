//============================================================================
// Name        : BasicExceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Can use exceptions to detect error conditions
// it helps to figure things that are not working
void mightGoWrong(){

	bool error1 = false;
	bool error2 = false;
	bool error3 = false;
	bool error4 = true;

	// exceptions get thrown all the way inside the call stack, of all the different functions that call each other
	if (error1){

		throw 8;
	}
	if (error2){

		throw "Something went wrong.";// if we throw a string, the type of it is going to be char
	}
	if (error3){

		throw string("Something else went wrong.");//throwing a string
	}
	if (error4){

		throw double(0.3);//throwing double
	}

}


// when there are errors, you can handle error messages with exceptions try and catch
int main() {


	try {
		mightGoWrong();
	}
	catch(int e){
		cout << "Int Error Code: " << e << endl;
	}
	catch(char const *e){
		cout << "Char Error Message: " << e << endl;
	}
	catch(string &e){
		cout << "String Error Message: " << e << endl;
	}
	catch(double &e){
		cout << "Double Error Code: " << e << endl;
	}

	cout << "Program still running" << endl;

	return 0;
}
