/*
 * Tvs.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <sstream>
#include <string>
#include "Tvs.h"

using namespace std;

Tvs::Tvs() {
	// TODO Auto-generated constructor stub
	cout << "Starting Tv database..." << endl;

	name = "Undefined";
	resolution = "";
	price = 0.0;

}

Tvs::~Tvs() {
	// TODO Auto-generated destructor stub
	cout << "Ending Tv database...." << endl;
}

Tvs::Tvs(string name,string resolution, double price){

	this -> name = name;
	this -> resolution = resolution;
	this -> price = price;
}

void Tvs::setTv(string name,string resolution, double price){

	this -> name = name;
	this -> resolution = resolution;
	this -> price = price;
}

void Tvs::setName(string tvName){

	name = tvName;
}


void Tvs::setResolution(string tvRes)
{
	resolution = tvRes;
}

void Tvs::setPrice(double tvPrice){
	price = tvPrice;
}



string Tvs::print(){
	stringstream ss;

	ss << "This is a  ";
	ss << name;
	ss << "Tv, It has a ";
	ss << resolution;
	ss << " Resolution, ";
	ss << "and its Price is £";
	ss << price << endl;

	return ss.str();
}
