//============================================================================
// Name        : FloatingPointTypes.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {


	float fValue = 68.9;

	cout << "Float number: " << fValue << endl;
	//cout can output numbers in various formats, notably two formats (the normal notation fixed and the scientific notation) and sometimes with bigger number cout can decide to switch between the two notations. to change that you can specify the notation using the include iomanip
	cout << "Float number with fixed notation: " << fixed << fValue << endl;
	cout << "Float number with scientific notation: " << scientific << fValue << endl;

	cout << "Float number with set precision and fixed notation: " << setprecision(20) <<  fixed << fValue << endl; //to use set precision you have to include iomanip, set precision allows you add or input the total number of decimal digits in a number

	cout << "Size of Float: " << sizeof(float) << endl;

	double dValue = 485.66905;
	cout << "Double number: "<< dValue << endl; // double  store number in a region of 15 significant digits
	cout << "Size of Double: " << sizeof(double) << endl;


	long double ldValue = 485.66905490589234;
	cout << "Long double number: "<< ldValue << endl;
	cout << "Size of Long Double: " << sizeof(long double) << endl;

	cout << "Long Double number with set precision: " << setprecision(10) << ldValue << endl;




	//comparing floating numbers
	float value = 2.3;

	if (value == 2.3){

		cout << "True " << endl;
	}else{
		cout << "False " << endl;

	}
	// you can't use == to compare floating types because you can't get the exact equal value of a float. its better to use </> to check or compare floating values
	cout << setprecision(1) << value << endl;

	return 0;
}
