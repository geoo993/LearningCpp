/*
 * Trainers.h
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#ifndef TRAINERS_H_
#define TRAINERS_H_

#include <iostream>
#include <sstream>

using namespace std;


class Trainers {
private:
	string name;
	string color;
	string brand;
	double price;

	string personName;
	string orderNumber;
	string trainersDetails;


public:
	Trainers();
	virtual ~Trainers();
	Trainers(string name, string color, string brand, double price);
	Trainers(string personName, string orderNumber, string trainersDetails): personName(personName), orderNumber(orderNumber), trainersDetails(trainersDetails){}
	void setTrainers(string name, string color, string brand, double price);
	string trainersInfo();
	string trainersOrder();
};

#endif /* TRAINERS_H_ */
