//============================================================================
// Name        : Polymorphism.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//this is a sub type polymorphism tutorial
class Animal{
public:

	// what virtual does is that it causes something called a V-table to be created behind the scene
	//this V-table enables c++ to look for the right specific method from the right subclass by the name of the subclass
	//so if you have a virtual method with keyword (virtual), then when you override it in sub classes, you get the right kind of method being called from the appropriate class for the actual object
//	virtual void speak(){
//		cout << "ANIMAL ?????????" << endl;
//	}

	virtual void speak()=0;// this implementation does not mean that it is equal to zero, this is a pure virtual method. it means that any descendant or base class of this super class type/method must have this implementation of this method in its class

	//destructors should generally be declared virtual, that is because every destructor created if often going to be cleaning up memory from your specific subclass
	//in general, you should make destructors virtual
	virtual ~Animal(){};

};

class Cat: public Animal{// Cat is sub class of Animal, Cat inherited from Animal

public:

	virtual void speak(){
		cout << "CAT MSMANNNNNS" << endl;
	}

	virtual ~Cat(){};
};

class HouseCat: public Cat{// HouseCat is sub class of Cat, HouseCat inherited from Cat
public:

	virtual void speak(){
			cout << "HOUSE CAT Meeoooowww" << endl;
		}
	virtual ~HouseCat(){};

};



int main() {

	// in sub type polymorphism, you can always used the derived class where a super class is expected
	// we can set the object/class to refer to any sub class type.
	// here we get the right type of method being called because of the virtual, the pointer will point at the super class but because the void method speak is virtual and used in the subclasses, we now get the appropriate method being called
	//you have to only declared the method in the super class virtual to get this kind of behaviour
	Animal * pAnimal = new Cat;
	pAnimal->speak();


	//virtual is acts like an override function, adding is virtual on any similar method makes it clear that this is a method that is overridden


	//always need to delete
	delete pAnimal;

	return 0;
}
