/*
 * Person.h
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>

using namespace std;

class Person {
private:
	string name;
	string age;
	string gender;


public:
	Person();
	~Person();
	void setPerson(string name, string age, string gender);
	void print();
	string getName();
	void setName(string newName);

};

#endif /* PERSON_H_ */
