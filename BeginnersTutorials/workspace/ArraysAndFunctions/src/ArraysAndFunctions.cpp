//============================================================================
// Name        : ArraysAndFunctions.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void show1(string texts[], const int length){

	for (int i=0; i<length; i++ ){
		cout << texts[i] << endl;
	}
}



//show2 is equivalent to show1
void show2(string *texts, const int length){

	for (int i=0; i<length; i++ ){
		cout << texts[i] << endl;
	}
}

//show3 we dont pass in the number of elements
void show3(string (&texts)[3]){// we are passing in a reference to an array of strings that is size 3, you have to have the right number size in this array for it to work and in this case is 3

	for (int i=0; i<sizeof(texts)/sizeof(string); i++ ){
		cout << texts[i] << endl;
	}
}



string *getArray(){
	// this is a bad pointer function that returns a local variable.
	string fruits[] = {"Apple", "Banana", "Strawberry"};//don't return pointers to local variables
	return fruits;
}

string numbers[] = {"One", "Two", "Three"};// this a global variable
// this is a better return array as oppose to getArray() which the pointer points to a local variable
string *getArrayNumbers(){
	return numbers;
}

//if you do need to return an array from a function, you can just return as a pointer which is very useful especially if you use the new operator in within your function
char *getMemory(){
	char *pMemory = new char[100];// this is okay to return because we are using new, explicitly allocating memory within the function which will need to be deleted when the function is called in your program
	return pMemory;
}

void freeMemory(char *pChar){// deallocating memory with function

	delete [] pChar;
}

int main() {

	string fruits[] = {"Apple", "Banana", "Strawberry"};

	show2(fruits, 3);

	show3(fruits);


	char *pMem = getMemory();
	//delete [] pMem;// it is your responsibility to free up this memory with delete
	freeMemory(pMem);// using free memory function to deallocate memory with delete


	return 0;
}
