/*
 * Person.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person() {
	// TODO Auto-generated constructor stub
	cout << "Listing Person..." << endl;

	name = "";
	age = "";
	gender = "";
}

Person::~Person() {
	// TODO Auto-generated destructor stub
	cout << "UnListing Person..." << endl;
}


void Person::setPerson(string name, string age, string gender)
{
	this -> name = name;
	this -> age = age;
	this -> gender = gender;
}

void Person::print() {
	cout << "Person Name : " << name << endl;
	cout << name << "age is " << age << endl;
	cout << name <<  " is a " << gender << endl;
}

string Person::getName(){
	return name;
}

void Person::setName(string newName){
	name = newName;
}
