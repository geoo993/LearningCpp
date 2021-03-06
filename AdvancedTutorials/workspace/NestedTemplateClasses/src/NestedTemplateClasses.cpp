//============================================================================
// Name        : NestedTemplateClasses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ring.h"

using namespace std;


// a class that supports a range based loop
// a collection type class, a ring buffer class
//nest template classes example

class test {
public:
	class iterator;
};

class test::iterator {
public:
	void print();
};

void test::iterator::print() {
	cout << "Hello from Test iterator..." << endl;
}


int main() {

	test::iterator it;
	it.print();

	ring<int>::iterator iter;
	iter.print();

	/*ring<string> textRing(3);//we can specify a maximum of 3 text rings
	textRing.add("one");
	textRing.add("two");
	textRing.add("three");
	textRing.add("four");//so if you add a forth one, it will just keep adding to the beginning

	//you would like to also terate through it and see it
	for(int i=0; textRing.size(); i++){
		cout << textRing.get(i) << endl;
	}*/

	return 0;
}
