/*
 * Cat.h
 *
 *  Created on: Sep 6, 2016
 *      Author: GeorgeQuentin
 */

#ifndef CAT_H_
#define CAT_H_
#include <string>


class Cat {
private:
	bool happy;// you can create a variable in class which can be accessed anywhere the class is being called, what ever you define in the class header can be access in the methods of the class which can be called where ever the class is being used


public:
	std::string noise();
	void makeCatHappy();
	void makeCatSad();
};

#endif /* CAT_H_ */
