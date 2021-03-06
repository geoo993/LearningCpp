//============================================================================
// Name        : Lists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

int main() {

	// list is similar to a vector but has some important differences
	//the difference is that you can insert items into a list at the beginning or the middle of the list, whereas with a vector you are just restricted to just adding items at the end
	// the reason for that is, with a vector all the different elements are stacked next to each other  in the computer memory
	// a list contains a bunch of nodes which stores each element, those nodes are linked to each other via pointers, so one node in the list has a pointer to the previous element/node and it also has a pointer to the next element/node
	//so with a list, you cant just use an index, you can get a pointer to next or previous elements and so on
	list < string > strings;

	strings.push_front("three");
	strings.push_front("two");
	strings.push_front("one");
	strings.push_back("four");
	strings.push_back("five");
	strings.push_back("six");

	//element at the start of the list
	list<string>::iterator itFirst = strings.begin();
	itFirst++;
	cout << "First element in list: " << *itFirst << endl;

	list<string>::iterator itLast = strings.end();
	itLast--;
	cout << "Last element in list:  " << *itLast << endl;

	//you can insert elements with iterator by pointing at a position in the list
	list<string>::iterator itErase = strings.end();
	strings.insert(itErase, "FithtyFive");

	const int V_SIZE = strings.size();// length or size of list
	cout << V_SIZE << endl;

	//we have to use an iterator, because we cannot just use an index
	for (int i = 0; i < strings.size(); i++) {
		//cout << strings[i] << endl;
	}

	for (list<string>::iterator it = strings.begin(); it != strings.end();) {

		if (*it == "FithtyFive") {
			it = strings.erase(it);
			cout << "Erazed element in list " << endl;
		} else {
			it++;
		}

		cout << *it << endl;
	}
	for (list<string>::iterator it = strings.begin(); it != strings.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;

	return 0;
}
