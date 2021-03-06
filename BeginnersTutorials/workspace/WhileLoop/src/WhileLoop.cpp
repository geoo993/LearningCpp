//============================================================================
// Name        : WhileLoop.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	// while loop checks the while condition before excecuting the code
	int i = 0;
	while (i <= 5) {

		cout << " Checking i => " << i << endl;

		//i = i + 1;
		//i++;
		++i;

	}
	cout << "Program Quit on " << i << endl;

	// do loop does the do code first before checking the while condition
	int value = 6;
	do {

		cout << "Do this when while is true" << "\n" << endl;
	} while (value < 4);

	const string password = "hello";// if you have a value that you do not want to be changed make it const (this is very similar to let in swift)
//	cout << "Enter Password > " << flush;
//	string input;
//	cin >> input;
//
//	while (input != password) {
//		cout << "Invalid Password " << "'" << input << "'" << endl;
//
//		cout << "Re-Enter Password > " << flush;
//		cin >> input;
//	}
//	cout << "Password Correct " << "'" << input << "'" << endl;


	string input;
	do {

		cout << "Enter Password > " << flush;

		cin >> input;

		if (input == password) {
			cout << "Password Correct " << "'"<< input << "'" << endl;
		} else {
			cout << "Invalid Password " << "'"<< input << "'" << endl;
		}

	}while (input != password);



return 0;
}
