//============================================================================
// Name        : Maps.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;

int main() {

	//maps is another most useful collection
	//map allows to store key values pairs, like a look up table, the idea is that you can store bits of information which you can retrieve with a key
	map <string, int> peopleAges; //the first part of the map is the key, and the next element is the value type inside the key

	// a map is just like a table
	peopleAges["Ziggy"] = 24;
	peopleAges["Geo"] = 23;
	peopleAges["Raj"] = 56;
	peopleAges["Zhan"] = 25;

	cout << "Raj: "<< peopleAges["Raj"] << endl;


	// another way to add elements in the map is to use pair and then insert it to the map
	pair<string, int> addToMap("Columbo", 67);
	peopleAges.insert(addToMap);

	//you can also use a function from standard(std) library called make_pair to create pairs
	pair<string, int> addToMap2 = make_pair("Barbara", 37);
	peopleAges.insert(make_pair("Celina", 13));
	peopleAges.insert(addToMap2);

	//when you try and access and element that is not in the map, it will return a empty initialiser
	cout << "Empty Key: "<< peopleAges["Sue"] << endl;

	cout << endl;

	//you can also iterate through map
	for (map<string, int>::iterator it = peopleAges.begin(); it != peopleAges.end(); it++){

		//must use arrow pointer to extract the values from the map
		cout << it->first << ": " << it->second << endl;//this is just for layout purposes where the string is first and the int is second
	}

	cout << endl;
	//you can also access or iterate with pair
	for (map<string, int>::iterator it = peopleAges.begin(); it != peopleAges.end(); it++){

		pair<string, int> peopleAge = *it;
		cout << peopleAge.first << ": " << peopleAge.second << endl;
	}
	//adding value with same key, you can do this because the keys in the map must and are always unique, its almost like it you are getting to their index like an array
	peopleAges["Raj"] = 42;
	cout << "Raj: "<< peopleAges["Raj"] << endl;



	//if you want to test the values in the map
	if (peopleAges.find("Adam") != peopleAges.end()){

		cout << "Found Adam" << endl;
	}else{

		cout << "Key is not found" << endl;
	}



	return 0;
}
