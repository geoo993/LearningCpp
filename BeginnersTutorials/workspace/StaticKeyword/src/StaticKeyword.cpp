//============================================================================
// Name        : StaticKeyword.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


//.h file
class Test {
// if you declare a variable static, it means that there is one version of that variable which is shared for all the objects, so the variable becomes associated with the class and not the object

private :
	//this means that it is shared to all objects of this Test class and it is associated with this Test class
	//when you create a static variable like this, you have to initialize it somewhere, because it is static the memory allocation will be create when you initialize the static variable
	static int count;

	int id;

	//you can define constants with static variables, it is traditional that when you define a constant you have it in capital letters
	//for constants you have to set the value as you create
	//it is quite common to define public static constants, it is not a problem because they cannot change but the can be accessed outside the class
public:
	//Initialization of constant must be done here
	static int const PILELENGTH = 25;

public:

	Test(){
		//this ++ incrementation after the value is called postfix increment operator
		//this will first add the value of count to id and then increment count
		//id = count ++;

		//this version is called prefix incrementation meaning the ++ operator will be incrementated first and then used
		// this will first increment the value of count and then assign count to id
		id = ++count;
	}

	int getId(){ return id; };

	// static methods are accessed via the class and they can only access static variables, meaning you can access instance variables or non static variable in a class because the method is static meaning it forbids it from happening
	static void showInfo(){
		cout << "We just accessed static variable count which is " << count << endl;
	}
};


//.cpp file source
int Test::count = 0;


// you can also create static methods, and again this will not be associate with particular objects but with the class
int main() {


	Test test1;
	cout << "test1 ID: " << test1.getId() << endl;
	Test test2;
	cout << "test2 ID: " << test2.getId() << endl;

	Test::showInfo();
	cout << "public static constant variable PILELENGTH is " << Test::PILELENGTH << endl;



	return 0;
}
