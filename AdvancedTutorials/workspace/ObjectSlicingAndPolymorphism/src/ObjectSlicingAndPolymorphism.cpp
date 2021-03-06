//============================================================================
// Name        : ObjectSlicingAndPolymorphism.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


// sport is the parent or super class of Tennis and Rugby
class Sport{
private:
	int one;
public:

	//object slicing means you can evoke the private variables of the other subclasses, nor can the subclasses access the private variables of this super class
	Sport(): one(1){

	}

	Sport(const Sport &other): one(0){
		one = other.one;
		cout << "copy parent and this is one " << one << endl;
	}

	// using virtual here will allow c++ to call this method in accordance to the call and sub classes. this is polymorphism
	virtual void print(){
		cout << "Sport" << endl;
	}

	virtual ~ Sport(){

	}
};

// Tennis sub class of sport
class Tennis: public Sport {
private:
	int two;
public:

	Tennis(): two(2)// cant access variable one from the supper class
	{

	}
	 void print(){
		cout << "Tennis is a Sport" << endl;
	}
};

// Rugby sub class of Sport
class Rugby: public  Sport {
private:
	int three;
public:

	Rugby(int t): three(t)// cant access variable one from the supper class
	{

	}
	void print(){
		cout << "Rugby is a Sport" << endl;
	}
};



int main() {


	Tennis t1;
	Sport &s1 = t1;//parent class pointing at child object
	s1.print();// when we print without adding virtual to the print method which is in all Sport classes. c++ will not look up the print anywhere else other than the supper class Sport. so you need to add virtual to all print methods so that c++ can figure out the right print to call

	Sport s2 = Rugby(2);// event here, we are calling the copy constructor, which at the moment has not got virtual
	s2.print();// so when we print, it will evoke the parent class constructor


	return 0;
}
