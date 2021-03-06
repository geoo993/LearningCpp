//============================================================================
// Name        : SwitchCase.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	//int value = 0;
	char value = 65;

	cout << "What is Value: " << value << endl << endl;

	const int characterNum = 64; // can insert constant number in switch case

	switch(value) {
	case 63:
		cout << "Value is ?" << endl;
		break;
	case 90:
		cout << "Value is Z" << endl;
		break;
	case 35:
		cout << "Value is #" << endl;
		break;
	case 36:
		cout << "Value is $" << endl;
		break;
	case 33:
		cout << "Value is !" << endl;
		break;
	case characterNum:
		cout << "Value is @" << endl;
		break;
	case 126:
		cout << "Value is ~" << endl;
		break;
	case 94:
		cout << "Value is ^" << endl;
		break;
	case 65:
		cout << "Value is A" << endl;
		break;
	default :
		cout << "Unrecognized Value" << endl;

	}

	return 0;
}
