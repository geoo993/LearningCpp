/*
 * Animal.cpp
 *
 *  Created on: Sep 8, 2016
 *      Author: GeorgeQuentin
 */
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	// TODO Auto-generated constructor stub
	cout << "Starting Animal Program..." << endl;
	name = "";
	group = "";
}

Animal::~Animal() {
	// TODO Auto-generated destructor stub
	cout << "Ending Animal Program..." << endl;
}

void Animal::print() const {

	cout << "A " << name << " is in the " << group << " category." << endl;
}
