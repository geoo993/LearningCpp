//============================================================================
// Name        : SortingVectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
	int id;
	string name;

public:

	Test() :
		id(0), name("") {
	}

	Test(int id, string name) :
		id(id), name(name) {
	}

	~Test() {
		//cout << "Destroyed Object" << endl;
	}

	void print() const {
		cout << name << ": " << id << endl;
	}

//	bool operator<(const Test &other) const {
//
//		if (name == other.name) {
//			return id < other.id;
//		} else {
//			return name < other.name;
//		}
//	}

	//this is a function prototype, amd what it does is that when it sees this function outside of the class,
	//or when you find a prototype of this function, we are going to make it a friend of this class, the function will then be able to access the private members or variables of the class
	friend bool comp(const Test &a, const Test &b);


};

//apply the prototype of this in the class
bool comp(const Test &a, const Test &b){
	return a.name < b.name;
}


int main() {

	vector<Test> tests;

	tests.push_back(Test(15, "Ela"));
	tests.push_back(Test(23, "Yousuf"));
	tests.push_back(Test(28, "Daniel"));
	tests.push_back(Test(42, "Daniel"));
	tests.push_back(Test(58, "Simba"));
	tests.push_back(Test(10, "Zelda"));

	//you can sort the vector, iterating with the sort type which takes the first element, and the the last element in the vector and it sort automatically
	//the sort takes the part or range of the vector that we want to sort
	//you must create an overloaded bool function in the class so that it can compare the elements
	//sort(tests.begin(), tests.end());

	//you cane sort with a function pointer like this, meaning you can supply your own function pointer to sort the elements in the vector
	//sort(tests.begin(), tests.end(), comp);

	// you can put a range as well, you do not have to go from first to last element
	sort(tests.begin(), tests.begin()+4, comp);

	for (int i = 0; i < tests.size(); i++) {
		tests[i].print();
	}

	return 0;
}
