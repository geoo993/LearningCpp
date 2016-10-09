/*
 * Animals.h
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef ANIMALS_H_
#define ANIMALS_H_


namespace toDogs {

const std::string DOGNAME = "Rex";// using standard namespace here to create variable

class Dog {
private:
	std::string name;
public:
	Dog();
	virtual ~Dog();
	Dog(std::string name): name(name){};
	void print();
};

}

#endif /* ANIMALS_H_ */
