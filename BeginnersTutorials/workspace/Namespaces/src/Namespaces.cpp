//============================================================================
// Name        : Namespaces.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Dog.h"
#include "Animals.h"

//using namespace std;
using namespace toDogs;


//namespaces are a way of avoiding conflicts between classes or variable, or even global variables that have the same name
// sometimes you get confusions with class names and namespace helps you avoid that, allowing you to have a more control of similar types of classes
// namespace are designed to avoid conflict between classes

int main() {


	Dog dog("Max");
	dog.print();

	//beside import the namespace by doing (using namespace), you can also create variables with the name space attached in front the variable
	dogs::Dog dog2("Jango");
	dog2.setType("Rottweiler");
	dog2.print();

	std::string text = "Hello";// using standard namespace on this variable because i haven't imported the standard namespace.
	cout << "String with Standard namespace called: " << text << endl;


	std::string getDogName = toDogs::DOGNAME;
	dogs::Dog dog3(getDogName);
	dog3.setType("Pitbull");
	dog3.print();


	cout << DOGNAME << " is a Dogs name. " << endl;// getting dogs name from the toDogs namespace used above or you can do (toDogs::DOGNAME) to get the DOGNAME in toDogs when the namespace is not specified above


	return 0;
}
