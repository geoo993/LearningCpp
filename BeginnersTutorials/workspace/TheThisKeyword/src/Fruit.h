/*
 * Fruit.h
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#ifndef FRUIT_H_
#define FRUIT_H_
#include <iostream>
#include <sstream>

using namespace std;

class Fruit {
private:
	string name;
	string color;

public:
	Fruit();
	virtual ~Fruit();
	Fruit(string name, string color);
	string toString();
};

#endif /* FRUIT_H_ */
