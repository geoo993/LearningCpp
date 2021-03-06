//============================================================================
// Name        : BitwiseAnd.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	// to extract values from hexadecimals, you can use a bitwise  &operator
	//int color = 0x12345678;

	// the hex color(0x12345678) in above in bit is a 32 bit, meaning 1(1111) 2(1111) 3(1111) 4(1111) 5(1111) 6(1111) 7(1111) 8(1111)

	// two AND(&&) symbol in cpp is the logical and meaning. its like boolean logic, but when you use a single AND(&), it does a bitwise comparison
	// what this bitwise AND will do is, it will look in each bit in color and the hex(0xFF000000), compare them and return the value that is not zero
	//for example if we have compare 11101001001101100100010101001110
	//with                           11111111111100000000000000000000
	//result is                      11101001001000000000000000000000
	//so when we compare color(0x12345678) with 0xFF000000, we get something like 0x12(000000)
	//int red = color & 0xFF000000; //is 12000000
	//int red = (color & 0xFF000000) >> 16; //now we shift this two bites along



	int color = 0x123456;


	unsigned char red = (color & 0xFF0000) >> 16;
	unsigned char green = (color & 0x00FF00) >> 8;
	unsigned char blue = (color & 0x0000FF);


	cout << "r: " << hex << (int)red << endl;
	cout << "g: " << hex << (int)green << endl;
	cout << "b: " << hex << (int)blue << endl << endl;


	//or do the following to achieve the same thing
	unsigned char redAgain = color >> 16;
	cout << "r: " << hex << (int)redAgain << endl;

	//Bitwise or: |

	return 0;
}
