//============================================================================
// Name        : CustomObjectsAsMapValues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>

using namespace std;


class Person {

private:
	string name;
	int age;

public:

	Person(){};
	Person(const Person &other){
		cout << "Copy constructor running." << endl;
		name = other.name;
		age = other.age;
	}
	Person(string name, int age): name(name), age(age)
	{

	}

	void print() {
		cout<< name << ": "<< age << endl;
	}

};

int main() {

	map <int, Person> people;
	people[0] = Person("Ziggy", 24);
	people[1] = Person("Geo",23);
	people[2] = Person("Raj", 56);
	people[4] = Person("Zhan", 25);
	people[3] = Person("Celina", 13);

	for (map<int, Person>::iterator it = people.begin(); it != people.end(); it++){

		cout << it->first << "= " << flush;
		it->second.print();
	}


	return 0;
}
