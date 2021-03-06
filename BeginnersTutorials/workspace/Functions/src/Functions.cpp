//============================================================================
// Name        : Functions.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void showMenu(){// this is a block of code, which essentially defines a function

	cout << endl << "1.\tSearch " << endl;
	cout << "2.\tView Record" << endl;
	cout << "3.\tQuit Program " << endl << endl;

}

string processingSelection(int getInput){//non void function as its returning string data

	switch (getInput) {
	case 1:
		return "Searching";
		break;
	case 2:
		return "Viewing";
		break;
	case 3:
		return "Quitting";
		break;
	default:
		return "Please select an item from the Menu";
		//continue;
	}

}

void searchNumber(int i) {// this is a recursive function that uses a recursive loop as oppose to a for loop
	cout << "The number is: " << i << endl;
	i++;
	if(i<10) {
		searchNumber(i);
	}
}


int main() {

	//FUNCTIONS
	//sub routines are usually known as functions,
	//a function is just a separate piece of code which you can invoke anywhere in your scripts. you can cause it to run where ever you like in your program
	//functions are methods which are done within or are part of a class
	//void essentially means that we are not returning any data when calling the function


	int value = 0;
	searchNumber(value);//calling a recursive function

	showMenu();// we are calling or invoking the function showMenu

	int input;
	do {

		cout << "Enter Selection > " << flush;

		cin >> input;
		string data = processingSelection(input);
		cout << data << endl;//calling non void function which returns an element (in this case string)

	} while (true);


	return 0;
}




