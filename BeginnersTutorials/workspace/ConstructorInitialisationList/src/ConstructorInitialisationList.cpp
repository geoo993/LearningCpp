//============================================================================
// Name        : ConstructorInitialisationList.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>

#include "Trainers.h"
using namespace std;

int main() {

	Trainers trainers1("Air Forces", "Gray", "Nike", 59.99);
	Trainers trainers2("Mens Converses", "White", "Converse", 39.99);


	string trainers2Details = trainers2.trainersInfo();

	Trainers trainers3("George","DES29GA12", trainers2Details );

	cout << trainers1.trainersInfo() << endl;
	cout << trainers3.trainersOrder() << endl;


	return 0;
}
