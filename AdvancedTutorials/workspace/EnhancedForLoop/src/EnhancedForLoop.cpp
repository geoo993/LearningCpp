//============================================================================
// Name        : EnhancedForLoop.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	//char texts[] = {"one", "two", "three"};
	auto texts = { "one", "two", "three" };// in c++ 11 you do not need a type declaration anymore


	for(auto text: texts) {
		cout << text << endl;
	}

	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);

	for(auto number: numbers) {
		cout << number << endl;
	}

	string hello = "hello";
	for(auto c: hello) {
		cout << c << endl;
	}

	for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); it++) {
		cout << *it << endl;
	}
	for (auto it = numbers.begin(); it < numbers.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}
