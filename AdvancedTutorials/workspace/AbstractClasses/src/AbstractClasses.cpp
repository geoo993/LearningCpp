//============================================================================
// Name        : AbstractClasses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// an abstract class is a class containing methods which have no implementation and we say that they are pure virtual functions/methods
class Animal {

public:
	//in this case, Animal is an abstract class, because it has pure virtual methods, it is called an abstract class
	//because Animal is an abstract class, we cannot instantiate it because abstract classes cannot be instantiated
	virtual void print() = 0; //this is a pure virtual function, a class which contains a pure virtual function is called an abstract class
	virtual int age(int age) = 0;
};


class Dog: public Animal {

public:
	virtual void print() {
		cout << "Dog: woof! woof! woof!" << endl;
	}
};

// now dog has become a virtual class, because Chiwawa has become a sub class that uses a virtual function that derives from dog
class Chiwawa: public Dog {


public:
	Chiwawa() {
		cout << "New Chiwawa " << endl;
	}
	virtual int age(int a){
		return a;
	}
};

class Cat: public Animal {
public:

	virtual void print() {
		cout << "Cat meoww! meooow!" << endl;
	}
	virtual int age(int a){
		return a;
	}
};


void anim(Animal &a){
	a.print();
}

int main() {

	Cat cat;
	cat.print();

	Chiwawa chi;
	chi.print();
	cout << "Chiwawa Age: " << chi.age(5) << endl;


	//you cannot create an array of animals still because its an abstract class but you can do so with Cat or Chiwawa, mainly because they are not abstract classes
	Chiwawa chis[5];
	chis[2].print();


	//you can actually create an array of pointers to animal
	Animal *animals[7];
	animals[0] = &chi;
	animals[1] = &cat;
	animals[1]->print();

	// you can also call the classes from a function
	anim(*animals[0]);
	anim(chi);

	return 0;
}
