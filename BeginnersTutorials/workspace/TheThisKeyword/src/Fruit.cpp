/*
 * Fruit.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <sstream>

#include "Fruit.h"
using namespace std;


Fruit::Fruit() {
	// TODO Auto-generated constructor stub
	cout << "Started Fruit Program..." << endl;

	name = "Undefined Name";
	color = "Undefined Color";
}

Fruit::~Fruit() {
	cout << "Ended Fruit Program..." << endl;
	// TODO Auto-generated destructor stub
}

Fruit::Fruit(string name, string color){

	// "this" is a variable that contains the memory location of each individual object that you create, so this is a pointer that refers back to a variable, its a pointer variable
	this -> name = name;// this allows you to refer to the variable (name in the fruit class) from the constructor to not form any confusion with the variable (the name thats is passed in the function) passed in the function
	this -> color = color;// when putting this in from of color. cpp will know that you mean the color variable in the class as oppose to color passed in this function

	cout << "Memory Location of object is " << this << endl;
}

string Fruit::toString(){
	stringstream ss;

	ss << "This ";
	ss << name;
	ss << " is ";
	ss << color;


	return ss.str();
}
