/*
 * Dog.cpp
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */
#include <iostream>
#include "Dog.h"
using namespace std;

namespace dogs{

Dog::Dog() {
	// TODO Auto-generated constructor stub
	cout << "Started Program in contructor...." << endl;

	name = "";
}

Dog::~Dog() {
	// TODO Auto-generated destructor stub
	cout << "Program ended by destructor...." << endl;
}

}