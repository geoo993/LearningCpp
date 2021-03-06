//============================================================================
// Name        : NewProject.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> vc = {"One","Two","Three"};

int main() {

	//to work with postfix and prefix value, the value has to be an integer type

	//this is the postfix increment operator, to increase the value
	int value = 10;
	//value++;

	//this is the postfix of the decrement operator, to decrease the value
	//value--;


	//this is prefix increment operator, to increase the value
	//++value;

	//this is prefix of the decrement operator, to decrease the value
	//--value;
	//cout << value << endl;



	//the different between postfix and prefix is that if you have an expression like the one bellow
	//with postfix the value is going to be used and then incremented, but with prefix the value is incremented first and then used.

	// postfix, the value is first used before incrementation
	cout << value++ << endl;
	cout << value << endl;

	// prefix the incrementation happens and then the value is used
	//cout << ++value << endl;
	//cout << value << endl;


	int number = ++value;//++;
	cout << "Number is: "<< number << endl;
	cout << "Value is Now: "<< value << endl;

	return 0;
}
