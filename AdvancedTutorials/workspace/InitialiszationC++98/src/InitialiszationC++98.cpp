//============================================================================
// Name        : InitialiszationC++98.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {


	int values[] = {1,2,3,4,5};

	cout << values[0] << endl;

	class S1 {
	public:
		string text;
		int id;
	};

	S1 s1 = {"hello", 6};
	cout << s1.text << s1.id << endl;

	//by default members of this are public
	struct S2 {
		string text;
		int id;
	};

	S2 s2 = {"hello", 6};
	cout << s2.text << s2.id << endl;

	//initialising struct
	struct S3 {// if you dont want to use this again you can remove the struct name
		string text;
		int id;
	} s3 = {"Hi", 35}, s4 = {"Todo", 4};
	cout << s3.text << s3.id << endl;
	cout << s4.text << s4.id << endl;

	vector<int> valuesInt;
	valuesInt.push_back(1);
	valuesInt.push_back(2);
	valuesInt.push_back(3);

	return 0;
}
