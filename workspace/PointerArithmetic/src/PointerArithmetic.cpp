//============================================================================
// Name        : PointerArithmetic.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int NUMBEROFSTRINGS = 5;// its good to puts constants in capital letters so that you know their difference with other variables

	string  texts[NUMBEROFSTRINGS] = {"one", "two", "three", "four", "five"};

	string *pTexts = texts;

	pTexts = pTexts + 1; // you can use arithmetics to check other elements in array, which in this case one becomes two based on the + 1
	cout << *pTexts << endl;

	pTexts = pTexts + 3;// this moves the pointer forward by 3 steps, from being at two and now its at five
	cout << *pTexts << endl;

	pTexts -=  2;// this moves the pointer back by 2 steps, from being at five and now its at three
	cout << *pTexts << endl;

	//set pTexts back to start
	pTexts = texts;

	string *pEnd = &texts[NUMBEROFSTRINGS];

	while(pTexts != pEnd){
		cout << *pTexts << endl;
		pTexts++;
	}

	//set pTexts back to start
	pTexts = &texts[0];
	long int elements = (long)(pEnd - pTexts);// points are actually long int types instead of normal int. here we are making the pointer point to the last pointer in array, which is the fifth pointer

	cout << elements << endl;

	//set pTexts back to start
	pTexts = &texts[0];
	//suppose you want a pointer to point in the middle of the array

	pTexts += NUMBEROFSTRINGS/2; // NUMBEROFSTRINGS/2 will always give you a value without a remainder, so it will be a safe value which you can use to go the element in the middle of the array
	cout << *pTexts << endl;

	return 0;
}
