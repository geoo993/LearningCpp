//============================================================================
// Name        : PrototypesAndIncludes.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// when the program begins to run/builds, it goes through several stages, firstly it goes through a process called the pre-processor and the pre-processor looks for statements beginning with hash (#) symbols and follow their commands, this is how we are able to add the include elements and check the related files that will process your programs
#include <iostream>//include with angle brackets are files which the computer already know about which are in a special area/standard location in your computer which the compiler know about
#include "utils.h"//include with double quote are to locate file that are in the project, they are files that are actually included in your project
using namespace std;

//putting a prototype of a function above main allows you to create that function anywhere at any position in your program
void doSomething();//this bit of a function is called a prototype, it allows you to define/name a function without having to create all the details inside the function
string name(string text);
int militaryTime(int hour, int min);


int main() {

	doSomething();
	name("Geo");
	militaryTime(13,4);
	currency(20);

	return 0;
}


void doSomething(){

	cout << "Do this" << endl;
}

string name(string text){
	cout << "My name is " << text << endl;
	return text;
}

int militaryTime(int hour, int min){




	if (min >= 60){
		hour += 1;
		min = 0;
	}
	if( min < 0){
		min = 0;
	}

	if (hour >= 24 || hour < 0){
		hour = 0;
	}

	int resultTime = (hour*100)+min;
	cout << "It is "<< resultTime << " Hours." << endl;

	return resultTime;
}



//groups of related functions are typically put in their own file which here are Headers files
//what you need is to have prototypes of your related functions to be a able to use them in separate files
double currency(int amount){

	double money = (double)amount;
	cout << "You have £ " << money << endl;

	return money;
}

