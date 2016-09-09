//============================================================================
// Name        : Classes.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Cat.h"
#include "Countries.h"
using namespace std;

//CLASSES
//classes are a way of combining or packaging together data and sub routines

//you use class to allow the compiler to access another class from another file
//classes and header files are a way to organise your program
//classes where created to bundle data, representing the state or variable of things together with subroutines and methods to represent what a things/object/player/enemy/character etc...


void cat() {

	CatClass cat;

	cat.noise();
	cat.name();
	cat.colour();

}

int main() {

	cat();

	Country country;
	//cout << country.stringToInt("Cuba") << endl;

	string name;
//	string capital;
//	long int population;
//	string language;
//	string currency;

	do {

		cout << "Enter Country > " << flush;
		cin >> name;
		//	    cout << "Enter Capital >";
		//	    cin >> capital;
		//	    cout << "Enter Population >";
		//	    cin >> population;
		//	    cout << "Enter language >";
		//	    cin >> language;
		//	    cout << "Enter currency >";
		//	    cin >> currency;
		//
		//	    country.setCountry(name, capital, population, language,currency);
		//	    country.print();
		country.countryInfo(name);

	} while (true);

	return 0;
}

