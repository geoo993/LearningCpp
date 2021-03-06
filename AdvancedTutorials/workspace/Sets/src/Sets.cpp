//============================================================================
// Name        : Sets.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>

using namespace std;

class Test {
private:
	int id;
	string name;

public:

	Test() : id(0), name("") {}

	Test(int id, string name) : id(id), name(name) {}

	void print() const {
		//cout << id << ": " << name << endl;
		cout << name << ": " << id << endl;
	}

	bool operator<(const Test &other) const {
		//return id < other.id;
		return name < other.name;
	}
};

int main() {

	//a set only stores unique elements, you can use insert to insert elements to it but will only allow unique elemnts
	//set also arranges the elements in the set

	set<int> numbers;
	numbers.insert(45);
	numbers.insert(15);
	numbers.insert(23);
	numbers.insert(19);

	for (int i = 0; i < 10;) {
		i++;
		numbers.insert(i);

	}

	for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;

	set < string > names;
	names.insert("Carrey");
	names.insert("Jim");
	names.insert("Stacey");
	names.insert("Lucie");
	names.insert("Vaughan");
	names.insert("Abdul");
	names.insert("Tupac");

	for (set<string>::iterator it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}

	//find element in a set
	string checkThis = "Ramesh";
	set<string>::iterator itFind = names.find(checkThis);

	//so as long as it has not searched through the entire set and gone to the end of it, you continue searching
	if (itFind != names.end()) {
		cout << "Found: " << *itFind << " in the set" << endl;
	} else {
		cout << "Could not find: " << checkThis << " in the set" << endl;
	}

	//count is also a good way to check elements in a set, it will only return zero or one meaning true or false, when the element is out or inside the set
	if (names.count(checkThis) == 1) {//true
		cout << "Found: " << checkThis << " in the set" << endl;
	} else if (names.count(checkThis) == 0) {//false
		cout << "Could not find: " << checkThis << " in the set" << endl;
	}

	//defining set with classes
	cout << endl;
	set<Test> tests;
	tests.insert(Test(20, "Joe"));
	tests.insert(Test(18, "Mary"));
	tests.insert(Test(36, "Max"));
	tests.insert(Test(32, "Leyla"));

	for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
		it -> print();
	}

	return 0;
}
