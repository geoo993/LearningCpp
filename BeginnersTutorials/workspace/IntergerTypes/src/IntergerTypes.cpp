//============================================================================
// Name        : IntergerTypes.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>

using namespace std;

int main() {



	int value = 22078;// there's a limit to the amount you can store on an int, a bigger number like 2789367912078 will only return a number no bigger than 2147483647
	cout << "My interger: "<< value << endl;
	cout << "Max int value: " << INT_MAX << endl; // inlude limits allows you to call INT_MAX (2147483647), this is the maximum value that you can store in an int
	cout << "Min int value: " << INT_MIN << endl;// this is the minimum value that you can store in an int
	// INT_MAX or INT_MIN are like constant that you can generate from using include limits
	cout << "Size of int: " << sizeof(int) << endl; //sizeof is technically an operator, you can type a variable name inside on a intergerType like int
	//output of sizeof(int) = 4 meaning 4 bites



	//short sValue = 6380; //or
	short int sValue = 6380; // short int allows you to store small interger
	cout << "my short interger: "<< sValue << endl;
	cout << "short Max int: "<< SHRT_MAX << endl;
	cout << "short Min int: "<< SHRT_MIN << endl;
	cout << "Size of short int: " << sizeof(short int) << endl;
	//output of sizeof(short int) = 2 meaning 2 bites

	//long lValue = 639802801902380;  //or
	long int lValue = 639802801902380; // long int allows you to have a bigger interger than int
	cout << "my long interger: "<< lValue << endl;
	cout << "Max long int: "<< LONG_MAX << endl;
	cout << "Min long int: "<< LONG_MIN << endl;
	cout << "Size of long int: " << sizeof(long int) << endl;
		//output of sizeof(long int) = 8 meaning 8 bites

	cout << "Size of long value: " << sizeof(lValue) << endl;



	signed int intValue1 = -367;// int by default are signed int which means they can be assigned negative or positive numbers
	cout << "this is a signed int: " << intValue1 << endl;

	unsigned int intValue2 = 98967;//however unsigned requires you to store only positive numbers
	cout << "this is an unsigned int: " << intValue2 << endl;


	return 0;
}
