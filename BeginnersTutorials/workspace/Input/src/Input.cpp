//============================================================================
// Name        : Input.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {


	string text = "Not Started";

	cout << text << endl; // cout is also an object and its a special object for outputing text,
	cout << "Hello, We are getting started " << endl;//the chevron (<<) is called the insertion operator, they are used to form an operation which in this case is used to insert data into the cout object to output text. :::: (+,=, -,/) are also operators

	cout << "Enter your name: " << flush;//the opposite if cout, to get text from the user is to use cin
	string inputText;
	cin >> inputText; // the extraction operator is >>, you use it to get data from the cin object which gets the data from the user inputs
	cout << "You entered: " << inputText << endl;


	cout << "You're about to enter a number: " << flush;
	int value;
	cin >> value;
	cout << "You entered: " << value << endl;

	cout << "You're about to enter a float number:" << flush;
	float floatValue;
	cin >> floatValue;
	cout << "You entered: " << floatValue << endl;


	return 0;
}
