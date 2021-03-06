//============================================================================
// Name        : OtherVariableTypes.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	bool isTrueFalse = false;

	cout << "bool: " << isTrueFalse << endl;// in cpp instead of outputting false/true, the compiler uses (zero/one) where zero is equivalent to false and one is equivalent to true

	bool isTrueFalseWithNumbers = 40;// in addition, you can use numbers in bool in cpp to represent false/true, where zero is false and any number that is not zero is true
	cout << "Bool with number: " << isTrueFalseWithNumbers << endl;
	cout << "Size of Bool: " << sizeof(bool) << endl;


	//char takes one bite of computer memory
	//char is partly intended to represent single characters from something called the ascii characters set
	//char is short for character, which is a data type that holds one character (string, number, etc.) of data
	char myCharacterArray[] = "Hello";
	char myCharacter1 = 'H';
	char myCharacter2 = 'HELLO';
	cout << "Character: " << myCharacter1 << endl;
	cout << "Takes the last character: " << myCharacter2 << endl;
	cout << "Character Array: " << myCharacterArray << endl;


	char asciiCharacter = 55;// cher here is outputting the character 7 from the ascii character list. There are 255 values in the ascii list and because char can only contains a bite, and as one bite can only represent 255 characters, the number 55 represents the 55th value which is a character type in the ascii list
	char characterNumber = '7';

	cout << "Ascii Character Number: " << asciiCharacter << endl;// the outputed 7 is the character 7 not number 7
	cout << "Character Number: " << characterNumber << endl;// this is the number 7 but not the character 7

	cout << "Casting ascii character to int: " << (int)asciiCharacter << endl;//you can also cast a char (this is called casting (int)7 ) to return the actual number instead of the ascii character

	char letterCharacter = 'r';
	cout << "Getting ascii value of character: " << (int)letterCharacter << endl;// you can also get the ascii value of a letter character

	//a char only store a number between -128 up to 127 which is  256 values


	cout << "Size of Char: " << sizeof(char) << endl;


	wchar_t wCharacter = 'u'; //wchar_t is intended for representing a greater range of characters that you can represent in char
	cout << "wCharacter returning char value: " << wCharacter << endl;// this is the same as casting char like above ( (int)letterCharacter  )
	cout << "cast wCharacter back to character using char: " << (char)wCharacter << endl;

	cout << "Size of wChar_t: " << sizeof(wchar_t) << endl;


	return 0;
}
