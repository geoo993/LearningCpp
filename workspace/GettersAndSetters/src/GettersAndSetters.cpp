//============================================================================
// Name        : GettersAndSetters.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
using namespace std;

int main() {

	// getters and setters are just for getting and setting values

	Person person;

	string name;
	string age;
	string gender;

	cout << "Enter Person Name > " << flush;
	cin >> name;
	person.setName(name);//this is called a setter, meaning your setting the value of a variable in the class
	cout << endl << "The person we met yesterday is called " << person.getName() << endl << endl;// here you are getting the value of the variable in the class


	cout << "Enter Age > " << flush;
	cin >> age;
	cout << "Enter Gender > " << flush;
	cin >> gender;

	person.setPerson(name, age, gender);
	person.print();




	return 0;
}
