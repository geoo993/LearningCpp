/*
 * Cat.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: GeorgeQuentin
 */

#include "Cat.h"
#include <iostream>

namespace catnamespace {

void saySomething() {
	std::cout << "HELLO CAT WORLD" << std::endl;
}

	Cat::Cat() {
		// TODO Auto-generated constructor stub

	}

	void Cat::speak() {
		std::cout << "meeeoooowwww !!!!" << std::endl;
	};

	Cat::~Cat() {
		// TODO Auto-generated destructor stub
	}

}
