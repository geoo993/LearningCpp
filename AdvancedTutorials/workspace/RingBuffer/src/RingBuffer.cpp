//============================================================================
// Name        : RingBuffer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ring.h"
using namespace std;

int main() {

	ring<string> textRing(3);//we can specify a maximum of 3 text rings
	textRing.add("one");
	textRing.add("two");
	textRing.add("three");
	textRing.add("four");//so if you add a forth one, it will just keep adding to the beginning

	cout << textRing.size() << endl;
	//you would like to also iterate through it and see it
//	for (int i = 0; textRing.size(); i++) {
//		cout << textRing.get(i) << endl;
//	}

	//textRing.erase(1);
	//cout << textRing.size() << endl;

	textRing.add("five");

	cout << textRing.front() << " " << textRing.back() << endl;

	cout << endl;

	for(ring<string>::iterator it = textRing.begin(); it != textRing.end(); it++ ){
		cout << *it << endl;
	}

	cout << endl;

	for(string value: textRing){
		cout << value << endl;
	}

	cout << endl;

	for(auto value: textRing){
		cout << value << endl;
	}

	cout << endl;
	for (int i = 0; textRing.size(); i++) {
		cout << textRing[i] << endl;
	}

	ring<int> r({2,3,4,5,6});
	cout << r.front() << endl;

	return 0;
}
