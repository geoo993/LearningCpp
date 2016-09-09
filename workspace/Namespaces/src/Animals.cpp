/*
 * Animals.cpp
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include "Animals.h"
using namespace std;


namespace toDogs {

Dog::Dog() {
	// TODO Auto-generated constructor stub
	name = "";
}

Dog::~Dog() {
	// TODO Auto-generated destructor stub
}

void Dog::print()
{
	cout << name << " is a dog from toDog namespace." << endl;
};

}
