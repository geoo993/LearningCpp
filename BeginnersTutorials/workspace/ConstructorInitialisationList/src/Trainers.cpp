/*
 * Trainers.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <sstream>

#include "Trainers.h"
using namespace std;

Trainers::Trainers(): name("Undefined"), color("undefined"), brand("Undefined"), price(0.0), personName(personName), orderNumber(orderNumber), trainersDetails(trainersDetails) ////this is a constructor initialiser list, cpp knows what these means and its a different way of naming and assigning the variables
{
	// you can mix between putting variable in constructor initializer or inside the constructor

	// TODO Auto-generated constructor stub
	cout << "Started Trainers Program...." << endl;
}

Trainers::~Trainers() {
	// TODO Auto-generated destructor stub
	cout << "Ending Trainers Program...." << endl;
}

Trainers::Trainers(string name, string color, string brand, double price): name(name), color(color), brand(brand), price(price) //this is a constructor initialiser, cpp knows what these means
{
}

void Trainers::setTrainers(string name, string color, string brand, double price)
{
	this -> name = name;
	this -> color = color;
	this -> brand = brand;
	this -> price = price;
}

string Trainers::trainersInfo(){

	stringstream ss;

	ss << "These are ";
	ss << color;
	ss << " ";
	ss << name;
	ss << " made by ";
	ss << brand;
	ss << ". They cost £";
	ss << price << endl;

	return ss.str();

}


string Trainers::trainersOrder(){

	stringstream ss;

	ss << "Hi ";
	ss << personName;
	ss << ", Your order number is ";
	ss << orderNumber;
	ss << " and these are the details of your order. ";
	ss << trainersDetails;

	return ss.str();

}
