/*
 * Tvs.h
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#ifndef TVS_H_
#define TVS_H_

#include <iostream>

using namespace std;


class Tvs {
private:
	string name;
	string resolution;
	double price;

public:
	Tvs();
	virtual ~Tvs();
	Tvs(string name, string resolution, double price);// constructor with parameters, we are defining the implementation
	//Tvs(string name, string resolution, double price){ name = name;resolution = resolution; price = price; }//this constructor can also be defined here in this way

	void setTv(string name, string resolution, double price);
	void setName(string tvName);
	void setResolution(string tvRes);
	void setPrice(double tvPrice);
	string print();

};

#endif /* TVS_H_ */
