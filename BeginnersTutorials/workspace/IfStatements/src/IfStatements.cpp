//============================================================================
// Name        : IfStatement.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {


//	string password = "hello";// = operation is to assign a value but == operation is to check a value
//
//	cout << "Enter Your Password>" << flush;
//
//	string input;
//	cin >> input;
//
//	if (input == password) // here we are checking that input and password are the same, this if statement is called a condition
//	{
//		cout << "Correct Accepted, You've logged in: " << "'" << input << "'" << endl;
//
//	}else{
//
//		cout << "Access Denied (Incorrect Password) " << "'" << input << "'" << endl;
//	}



	// this is tab space \t
	// this is next line \n

	cout << "\n1.\tAdd New Record." << endl;
	cout << "2.\tDelete Record." << endl;
	cout << "3.\tView Record." << endl;
	cout << "4.\tSearch Record." << endl;
	cout << "5.\tQuit." << endl;


	cout << "\nEnter Your Selection> " << flush;

	int value;
	cin >> value;

//	if (value < 2){
//		cout << "\n" << "Insufficient Privileges to use software " << endl;
//	}else {
//
//		cout << "\n" << "Sufficient Privileges " << endl;
//	}

	if (value == 1){
		cout << "Adding new Record... " << endl;
	}else if (value == 2){
		cout << "Deleting Record... " << endl;
	}else if (value == 3){
		cout << "Viewing ... " << endl;
	}else if (value == 4){
		cout << "Searching... " << endl;
	}else if (value == 5){
		cout << "Application Option... " << endl;
	}else{
		cout << "Invalid Selection " << endl;
	}



	return 0;
}