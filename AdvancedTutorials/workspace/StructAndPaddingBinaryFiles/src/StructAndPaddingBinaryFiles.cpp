//============================================================================
// Name        : StructAndPaddingBinaryFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

// how to write a struct in a binary file

//the only difference between a struct and a class is that the members of a struct are public by default
//structs are mostly used to write into files
//c++ pads structs to make them more efficient to transfer them to and from memory
//struct Person{

#pragma pack(push, 1)//you can turn off the padding by pushing the directive on top of some stack
// what we are doing by saying 1, is to align the data and whatever follows on single bytes boundaries

struct Person{

	//when trying to store for example a text, that text is not directly stored in this variable
	//when we declare variables in c++, they are stored in an area of memory known as a stack, this is a relatively small area of memory thats used for storing variables or for keeping track of function calls.
	//we cannot use string because it allocates extra memory to store the actual text
	//string name;

	char name[50];
	int age;
	double weight;

};

#pragma pack(pop)// here we surround the pack, and this will undo the push we done above, and set us back to normal on the stack. this is for the sake of efficiency

//now we can write this struct directly to a file. as we have unpadded with pragma


int main() {

	Person p;

	//you can check how the padding works by just calling the sizeof Person, it will always be an even number and that is because of the padding that is done to it.
	cout << sizeof(p) << endl;//this should be 62, but it is 64 because of the padding done in c++


	return 0;
}
