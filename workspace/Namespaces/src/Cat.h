/*
 * Cat.h
 *
 *  Created on: Sep 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef CAT_H_
#define CAT_H_

class Cat {
private:
	string name;
	string color;

public:
	Cat();
	virtual ~Cat();
	void print();
};

#endif /* CAT_H_ */
