//============================================================================
// Name        : FunctionPointers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//function pointers have been around for a long time
//in c++ 11, you can use lambda expressions as alternative to function pointers
//same way you can declare pointer to a variable, you can also do the same for functions, so you can actually pass a block of code to another function
//the virtual keyword is an example of an already created function, the virtual keyword is an instruction to call c++ to create a v table (virtual table), which is a table of function pointers
// virtual key word sends the instruction or call to the parent class function type, so when you call a method from a child class that uses virtual or via pointer to the parent call type, c++ can do a look up on table of functions pointer and find the right appropriate function to call


void test(){
	cout << "Hello " << endl;
}

const void date(int day){
	cout << day << "th Of November " << endl;
}

string fullName(string forename, string surename){
	return forename + " "+ surename;
}


bool match (string s){
	//return s == "two";
	return s.size() == 3;
	//return s.size() > 3;
}

int countIf(vector<string> check, bool (*pMatch)(string s) ){

	int count = 0;

	for(int i = 0; i < check.size(); i++){

		if (pMatch(check[i])){
			count ++;
		}
	}

	return count;
}


int main() {

	//normal function call
	test();


	// when we create the type of the variable of the actual pointer to a function, we are not going to need a function name in there
	// we are just going to need a pointer, something that points to the function
	// in the case of void return type like the test function above, which takes no parameters, we will need to use the return type of it to create the function pointer
	// so its a void type function with no parameters
	void (*pTest)();//this is now a variable called pTests which is a pointer to a function, that has no parameters

	//now we use the variable function pointer to point to the desired function
	pTest = &test;//here we are pointing to the test() function (pointing by getting the address)
	//(*pTest)();//now we are pointing and calling the function, so we are calling function test via pointer function to it called pTest

	pTest();//we do not really need the * to point to it, or the brackets, we call just call it like this as well


	//to make things simple, we can also pointing to the function when we are initialising the variable
	const void (*pDate)(int day) = &date;
	pDate(4);

	//in the parameter, you do not really have to specify the data, you can just add the element type in the parameter list
	string (*pName)(string, string) = fullName;
	cout << pName("George", "Quentin") << endl;


	//using function pointer
	vector<string> tests;
	tests.push_back("one");
	tests.push_back("two");
	tests.push_back("three");
	tests.push_back("four");
	tests.push_back("five");
	tests.push_back("six");
	tests.push_back("seven");
	tests.push_back("eight");
	tests.push_back("nine");
	tests.push_back("ten");

	cout << match("one") << endl;

	// you can use this count_if using include algorithm, and pass it an iterator to the start of the range that you want to iterate or check and pass the end range as well
	cout << count_if(tests.begin(), tests.end(), match) << endl;// this will give a summary of how many times the bool true, meaning it will give the result of how many times the match function is true

	//in the case where you want to do the similar thing like count_if, where you want to pass in a block of code.
	//we can implement out own version of count_if using a pointer function
	cout << countIf(tests, match) << endl;


	return 0;
}
