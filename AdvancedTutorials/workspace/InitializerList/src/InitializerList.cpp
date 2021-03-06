//============================================================================
// Name        : InitializerList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;


class Test {
public:
	//we want to initialiser a Test of strings
	Test(initializer_list<string> texts){// what type of thing we use to initialise this

		for(auto value: texts){
			cout << value << endl;
		}
	}

	void print(initializer_list<string> texts){
		for(auto value: texts){
			cout << value << endl;
		}

	}
};


int main() {
	vector<int> numbers{1,2,3,4,5,6};
	cout << numbers[2] << endl;

	Test test{"one", "two", "three", "four"};

	cout << endl;

	test.print({"apple", "pear", "banana", "orange"});

	return 0;
}
