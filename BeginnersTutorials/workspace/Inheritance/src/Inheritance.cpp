//============================================================================
// Name        : Inheritance.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



class Animal {//spuer class

	//this is the super class of Cat.
private:
	string name;

public:

	Animal(string name=""): name(name){};
	void setName(string name){ this -> name = name; };
	void print(){ cout << "Animal Name is: " << name << endl; };
};

class Cat: public Animal {//this Cat class is the sub class of Animal, here we say Cat is sub class of Animal as it extends Animal, or we can say that it is inherited from Animal
	//here you are adding more things that the superclass does not have
private:
	string color;
public:
	string catColor(string color){ this -> color = color; return color; };
	void jump(){ cout << "Cat Jumping and has " <<  color << " color. " << endl; };
};

class Tiger: public Cat {//once again this is a subclass of other class, Tiger is a subclass of Cat, which is also a subclass of Animal. this is a much further inheritance
public:
	void attack(){ cout << "Tiger Cat attacked deer." << endl; };

};
int main() {

	//inheritance allows you to create new classes based on another class, which can have other functionality or just have a few things changed based on the other class
	//inheritance is when you create child classes or sub classes based on a particular class
	//the subclass/child class are a type of the super class, which in this case means, Animal is the super class and Cat is the subclass/child class of Animal class. Cat becomes a type of the Animal class
	Animal a("Max");
	a.print();

	Cat cat;
	cat.catColor("Brown and White");
	cat.jump();

	Tiger tiger;
	tiger.setName("Tiger");
	tiger.print();
	tiger.jump();
	tiger.attack();

	return 0;
}
