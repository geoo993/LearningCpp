//============================================================================
// Name        : TwosComplement.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int main() {

	//we set this char to the maximum value of char, meaning 127 is the maximum value that you can fit in a char.
	//you have to be wary of this because cpp will not give you any hint/warning on this and this may end up crashing or bugging your program
	//you have to be wary of this because cpp just does not check these when you run your program, it trust you that you know what you are doing, so be wary of maximum and minimum values of instances like char, ints (short, long), floats
	//just be aware of the storage capacity of integer types especially char because it has a small amount that you can set which is 127.
	char value = 127;
	cout << (int)value << endl;


	value ++;
	cout << (int)value << endl;// you get -128, which is the minimum value of a char


	//the biggest value that you could get in a 3-bit system is
	//111 = 4 (1*1 + 1*2 + 1*4)// which is 3 bit and result to 7
	//3 bit is essentially 2 to the power of 3 negative 1, same as (2x2x2 = 8 - 1)
	//1111 is 4 bit meaning 2 power 4 (2x2x2x2) = 16 - 1 = 15
	//11111 is 5 bit meaning 2 power 5 (2x2x2x2x2) = 32 - 1 = 31
	//111111 is 6 bit meaning 2 power 6 (2x2x2x2x2x2x) = 64 - 1 = 63
	//1111111 is 7 bit meaning 2 power 7 (2x2x2x2x2x2x2) = 128 - 1 = 127
	//11111111 is 8 bit meaning 2 power 8 (2x2x2x2x2x2x2x2) = 256 - 1 = 255

	//the computer is using the twos complement ???? check video for further details

	return 0;
}
