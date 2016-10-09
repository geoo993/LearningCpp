/*
 * Dog.h
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef DOG_H_
#define DOG_H_

#include <iostream>
using namespace std;

namespace dogs{

const string DOGNAME = "Buddy";


class Dog {
private:
	string name;
	string type;
public:
	Dog();
	virtual ~Dog();
	Dog(string name="", string type=""): name(name), type(type){};
	void setType(string type){ this -> type = type;};
	void print(){ cout << name << " is a "<< type << " dog." << endl;};
};

}

#endif /* DOG_H_ */
