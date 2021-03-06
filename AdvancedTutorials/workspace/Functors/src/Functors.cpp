//============================================================================
// Name        : Functors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Test {
	//this is now an abstract class
	virtual bool operator()(string &str) = 0;

	virtual ~Test(){}
};
//this is called a functor, a functor is a class or a struct that among other things, can overload brackets operators. so you can think of a functor as a function that does not have much to it than the overload operator
//but there s no reason for it not to have other elements or variables if you need it to
struct MatchTest: public Test{
	//we can overload the round () brackets operator this way
	//here, in the first round bracket, we are dealing with the round bracket operator and the second round bracket is the one that takes the argument lists, meaning the variables that you want to pass in
	bool operator()(string &str){
		//return str == "five";
		return str.size() == 3;
	}

};

// in c++ 11 you have lambda expressions which are syntactic sugar really for functor,
//here we are going to look at the pre c++ 11 syntax, which also works in c++ 11. which allows us to pass blocks of code around in variables
void check(string s, Test &t){

	if (t(s)){

		cout << s << " Matches the Test!"<< endl;
	}else{
		cout << s << " Does not Match the Test!"<< endl;
	}
}


int main() {

	// functors are another way of passing blocks of code to function, they are an alternative to function pointers
	// functors may have some advantages as oppose to function pointers
	MatchTest pred;
	string value = "fives";
	cout << pred(value) << endl;


	MatchTest m;
	check ("sos", m);
	return 0;
}
