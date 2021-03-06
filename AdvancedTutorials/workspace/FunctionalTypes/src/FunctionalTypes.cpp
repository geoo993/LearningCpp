//============================================================================
// Name        : FunctionalTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

//doing functional types helps or lets you easily define type equivalent to, used to reference any callable types in c++, meaning anything you can call with round brackets

//function bool
bool check(string &text){
	return text.size() == 4;
};


//functor
class Check {
public:
	bool operator()(string &text){
		return text.size() == 3;
	}
} check1;



void run(function<bool(string&)> check)//using functional here, lets say run can accept anything. we use ( function<> ) which is also a template type
{
	string text = "Dog";
	cout << check(text) << endl;// this is check will return true or false

}


int main() {

	const int SIZE = 5;
	vector <string> vec{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten"
	};

	auto ex = [&](string test){ return test.size() == SIZE;};

	int countThis = count_if(vec.begin(), vec.end(), ex);
	cout << countThis << endl;

	countThis = count_if(vec.begin(), vec.end(), check);
	cout << countThis << endl;

	countThis = count_if(vec.begin(), vec.end(), check1);
	cout << countThis << endl;


	run(ex);//return false
	run(check1);//return true

	function<int(int, int)> add = [](auto one, auto two){
		return one+two;
	};

	cout << add(4,8) << endl;

	return 0;
}
