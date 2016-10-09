/*
 * Cat.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <string>
#include "Cat.h"
using namespace std;

std::string Cat::noise() {

	if (happy) {
		return "Meeaaoowww";
	} else {
		return "Shhhsshshh";
	}
}

void Cat::makeCatHappy() {
	happy = true;
}

void Cat::makeCatSad() {
	happy = false;
}
