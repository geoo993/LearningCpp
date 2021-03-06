//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


// a vector is basically like a resizable array
int main() {

	// a vector is also called a template class in c++, that means you have to tell it what type of object its going to work with i.e. int, string etc...
	// vector of string type, a vector that contains strings
	// you can also pre size a vector just like an array
	//vector<string> strings(6);
	//cout << strings[3] << endl;

	vector<string> strings;

	//vector is resizeable it will automatically handle size and memory for you

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");
	strings.push_back("four");
	strings.push_back("five");
	strings.push_back("six");

	const int V_SIZE = strings.size();// length or size of vector
	cout << V_SIZE << endl;


	for (int i = 0; i < V_SIZE; i++){
		cout << strings[i] << endl;
	}

	//this will give something called an iterator, which points to the first element in the vector;
	vector<string>::iterator itFirstElement = strings.begin();//you can declare an iterator like this
	vector<string>::iterator itLastElement = strings.end();// so is the case for end

	// the iterator can also overload the increment operators like this
	//itFirstElement++;
	//itFirstElement += 3;

	//these iterators overloads the star(*) operator, you can now access those iterators as though it was a pointer, by dereferencing it
	//cout << *itFirstElement << endl;
	//cout << *itLastElement << endl;


	//here we are going to keep iterating until, or as long as the iterator does not refer to the end iterator
	//	for (itFirstElement; itFirstElement != itLastElement; itFirstElement++ ){
	//		cout << *itFirstElement << endl;
	//	}
	for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++ ){
		cout << *it << endl;
	}



	return 0;
}
