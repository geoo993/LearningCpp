/*
 * Animal.h
 *
 *  Created on: Sep 8, 2016
 *      Author: GeorgeQuentin
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
using namespace std;

class Animal {
private:
	string name;
	string group;

public:
	Animal();
	virtual ~Animal();
	Animal(string name, string group): name (name), group(group){}
	void setAnimal(string name, string group){ this ->name = name; this ->group = group; }

	//void print() const { cout << "A " << name << " is in the " << group << " category." << endl;}// if you got a methods that doesnt change an instance of a class like print does, just make it constant
	void print() const;// same as the print above
};
#endif /* ANIMAL_H_ */
