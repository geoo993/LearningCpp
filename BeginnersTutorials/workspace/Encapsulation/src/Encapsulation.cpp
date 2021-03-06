//============================================================================
// Name        : Encapsulation.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Frog {

	//here we are encapsulating, by hiding away properties of this class using private
	//here we encapsulate all the instance variable, making them private and hiding them away, so no one can mess with them
	//encapsulation allows you to hide away data which you do not want to mess with outside of a class, it is important to make as much private data, encapsulating them especially when you would not need to use them, so just encapsulate them with private.
	//if the end user does not need data or properties that you create, then encapsulate them by making them private which would keep those data safe and untangle/untouched
private:
	// instance data at top
	string name;
	int frogNum;

	//beside hiding away your instances of the class, encapsulation is also when you are hiding away methods which you do not want to be called outside of the class, however it can be called within the class.
	//you can declare different private or public methods anywhere at any order you want within your class
private:
	//methods data bellow
	int getFrogNumber(){ return frogNum; };

public :
	//we only provide public methods that can run the encapsulate elements of this class.
	//we declare the methods of the class because its public other wide they are being encapsulated in the class

	Frog(string name="", int frogNum=0): name(name), frogNum(frogNum){}
	void setName(string name){ this -> name = name; };
	void setFrogNumber(int frogNum){ this -> frogNum = frogNum; };
	string getName(){ return name; };

	//the private method getFrogNumber can only be called within this class because its been encapsulated in the class using private
	void info(){ cout << "Checking current frog..... Name: " << getName() << "   Number: " << getFrogNumber() << "." << endl; };
};



int main() {

	//this is an example of encapsulation at work,
	Frog frog("Toad");
	cout << "this Frog name is " << frog.getName() << endl;

	frog.setName("LAbs") ;
	cout << "this Frog new name is " << frog.getName() << endl;

	frog.setFrogNumber(12) ;
	frog.info();

	return 0;
}
