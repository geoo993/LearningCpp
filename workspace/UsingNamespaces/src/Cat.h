/*
 * Cat.h
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef CAT_H_
#define CAT_H_


#include <iostream>
using namespace std;

namespace cats{

class Cat {
private:
	string name;
	string color;

public:
	Cat();
	virtual ~Cat();
	void print();
};

}
