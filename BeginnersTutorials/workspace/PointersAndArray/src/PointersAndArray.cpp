//============================================================================
// Name        : PointersAndArray.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int stringToInt(string str) {

	const char* characters = str.c_str();

	int value = 0;
	for (int i = 0; i < strlen(characters); i++) {
		value = value + (int) characters[i];
	}

	return value;
}

int main() {

	string numbersWords[] = { "one", "two", "three" };

	string *pNumbersWords = numbersWords;// pointing at string array;

	int arrLength = sizeof(numbersWords) / sizeof(string);

	cout << "Array Length" << arrLength << endl;

	for (int i = 0; i < arrLength; i++) {
		cout << pNumbersWords[i] << " " << flush;// using the pointer to output the elements in string array
	}

	cout << endl;

//	for (int i = 0; i < arrLength; i++) {
//		cout << *pNumbersWords << " " << flush;// you can also derefference  the pointer to get the elements in original array, but this will only point to the first string.
//		pNumbersWords ++; //this now makes it so that you can reference all the elements in array. cpp knows that you want to access all other elements in array
//	}


	for (int i = 0; i < arrLength; i++, pNumbersWords++) {// you can also put in extra element that you want the array to run in third part of the for loop
		cout << *pNumbersWords << " " << flush;
	}

	cout << endl;

	string *pElement = &numbersWords[0];// this can also be written like this (&(numbersWords[0])). we are pointing to get the address of the first elements in array
	string *pEnd = &numbersWords[2];//this can also be written like this (&numbersWords[2]). we are pointing to get the address of the last element in array

	while(true){

		cout << *pElement << " " << flush;

		if (pElement == pEnd){//first pointer checks if it is equals to the other pointer, meaning you are checking/comparing elements in array with pointers
			break;
		}

		pElement ++;

	}

	return 0;
}
