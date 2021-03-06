//============================================================================
// Name        : Multimap.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<map>
using namespace std;

int main() {

	//multimap allows you to store values with duplicate keys
	//you declare a multimap the same way as a map
	//the only difference between multimap and map, is that in multimap you can have duplicate keys as oppose to map, if you have duplicate keys in map, the key will be unique all the time
	multimap<int, string> lookup;

	lookup.insert(make_pair(23, "Marvel"));
	lookup.insert(make_pair(34, "CapCom"));
	lookup.insert(make_pair(18, "DC"));
	lookup.insert(make_pair(18, "Bethesda Softworks"));
	lookup.insert(make_pair(10, "Konami"));
	lookup.insert(make_pair(18, "Manga"));

	for (multimap<int, string>::iterator it = lookup.begin(); it
			!= lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	for (multimap<int, string>::iterator it = lookup.find(12); it
			!= lookup.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}

	cout << endl;

	//here we are checking for duplicates by comparing values in the multimap, we are iterating through a range of keys
	pair < multimap<int, string>::iterator, multimap<int, string>::iterator > its = lookup.equal_range(18);
	//auto its = lookup.equal_range(18);

	for (multimap<int, string>::iterator it = its.first; it
			!= its.second; it++) {
		cout << it->first << ": " << it->second << endl;
	}

	return 0;
}
