//============================================================================
// Name        : Conditions.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;


/* LIST OF C++ CONDITIONS
 * == is equal to
 *!= is not equal to
 *< less than
 *<= less than or equal to
 *> greater than
 *>= greater than or equal to
 *|| or (this is an operator, and can be used with condition statements)
 *&& and (this is an operator, and can be used with condition statements)
 *% return module even or odd
 *%= check modular condition is zero or one
 */
int main() {

	int value1 = 4;
	int value2 = 10;

	if (value1 > 2 && value2 <= 20){
		cout << "Condition 1 is True" << endl;
	}else{
		cout << "Condition 1 is False" << endl;
	}


	if (value1 <= 2 && value2 > 12){
		cout << "Condition 2 is True" << endl;
	}else{
		cout << "Condition 2 is False" << endl;
	}

	if (value1 < 6 || value2 >= 12){
		cout << "Condition 3 is True" << endl;
	}else{
		cout << "Condition 3 is False" << endl;
	}

	if (value2 != 8){
		cout << "Condition 4 is True" << endl;
	}else{
		cout << "Condition 4 is False" << endl;
	}

	bool chechThatCondition = (value1 <= 1 && value2 > 2);
	bool chechThisCondition = value1 < 20;

	if (chechThatCondition || chechThisCondition )
	{
		cout << "Condition 5 is True: " << endl;
	}else{
		cout << "Condition 5 is False: " << endl;
	}

	bool isTrueFalse = false;
	int value3 = isTrueFalse ? 10 : 5;
	cout << "Number is: " << value3  << endl;

	string text = isTrueFalse ? "true" : "false";
	cout << "Bool value is " << text  << endl;


	int value4 = 5;

	if (value4 %= 2){
		cout << "Modular, this is an Even Number: " << value4  << endl;
	}else{
		cout << "Modular, this is an Odd Number: " << value4  << endl;
	}


	int value5 = 7;
	value5 ^= 2;
	cout << "This is strange: " << value5 << endl;


	return 0;
}
