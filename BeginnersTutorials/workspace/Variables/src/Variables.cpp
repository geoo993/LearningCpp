//============================================================================
// Name        : Variables.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const string description = "string cannot change when const is assigned";// const means that later in the program the value of this variable cannot be altered


char myCharacterArray[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
char aChar = 'A', bChar = 'B', cChar = 'C';
char myCharacterArr[] = "Hello";

double aDouble = 1.0 / 81;
double bDouble = 0;
double da = 1.0;
//long double

float aFloat = 1.f / 81;
float fc = 3.9999999f;


bool isItTrueFalse = false;


// declaring variables:
int a, b;
int result;

int main() {

	// process:
	a = 5;
	b = 2;
	a = a + 1;
	result = a - b;

	int randomNumber = rand(); //generate random number
	cout << randomNumber << endl;

	int numberCats = 5;
	int numberDogs = 8;

	string cats = "Number of Cats: ";
	string dogs = "Number of Dogs: ";
	string allAnimals = "Number of Animals: ";


	cout << cats << numberCats << endl;

	numberDogs += 1;
	cout << dogs << numberDogs << endl;


	int totalNumberOfAnimals = numberCats + numberDogs;
	cout << allAnimals << totalNumberOfAnimals << endl;


	return 0;
}





