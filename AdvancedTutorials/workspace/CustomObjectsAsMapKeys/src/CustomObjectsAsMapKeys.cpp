//============================================================================
// Name        : CustomObjectsAsMapKeys.cpp
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

	Person() {
	}

	Person(const Person &other) {
		//cout << "Copy constructor running." << endl;
		name = other.name;
		age = other.age;
	}
	Person(string name, int age) :
		name(name), age(age) {
	}

	void print() const {
		cout << name << ": " << age << flush;
	}

	//operation overloading, we call this an operator overloading, in the sense that we give it a new overloaded meaning
	bool operator<(const Person &other) const {

		if (name == other.name) {
			return age < other.age;
		} else {
			return name < other.name;
		}
	}

};

int main() {

	map<Person, int> people;

	people[Person("Ziggy", 24)] = 1;
	people[Person("Geo", 23)] = 3;
	people[Person("Raj", 56)] = 5;
	people[Person("Zhan", 25)] = 2;
	people[Person("Celina", 13)] = 4;
	people[Person("Raj", 37)] = 7;

	people.insert(make_pair(Person("Alex", 8), 6));

	for (map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {

		cout << it->second << "= " << flush;
		it->first.print();

		cout << endl;
	}

	return 0;
}
