//============================================================================
// Name        : LambdaCapturingThis.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
private:
	int one = 1;
	int two{2};

public:

	void setOne(int one){
		this -> one = one;
	}
	void setTwo(int two){
		this -> two = two;
	}

	void run(){
		int three{3};
		int four{4};

		//auto pLambda = [this, three, four]()//this allows you to capture the private class instances by reference
		[&, this]()
		{
			setOne(311);
			setTwo(3222);
			cout << one << endl;
			cout << two << endl;
			cout << three << endl;
			cout << four << endl;
		}();

		//pLambda();


	}
};

int main() {

	Test test;

	test.setOne(111);
	test.setTwo(222);
	test.run();


	return 0;
}
