//============================================================================
// Name        : VectorsAndMemory.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main() {


	//vector <double> numbers(20, 1.7);// here we are pre-sizing the vector to 20 element and each elements value is 1
	//vector <double> numbers(0);
	vector <double> numbers(20);

	const int NUMBERS_SIZE = numbers.size();

	cout << "Size: " << NUMBERS_SIZE << endl;

	//capacity returns the number of elements that can be held in currently allocated storage
	int capacity = numbers.capacity();//a vector has a method called capacity, this is the size of the internal array that the vector is using and that size s going to increase in steps as you add elements to the vector

	cout << "Capacity: " << capacity << endl;

	for (int i = 0; i < 10000; i++){

		if (numbers.capacity() != capacity){
			capacity =  numbers.capacity();
			cout << "Capacity: " << capacity << endl;//this outputs the capacity whenever it changes
		}

		numbers.push_back(i);
	}

	// you also simply resize the vector instead of clearing all the elements
	numbers.resize(100);


	//numbers.clear();// this removes all the elements in the vector

	//when you clear all the elements in the vector the size changes but the capacity remains the same that is because the size of the internal array is just the amount of storage memory of the vector
	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;

	//reserve should have any affect to your code, the thing behind reserve is for you to increase the capacity to a certain amount, so you can allow for more storage space for your vector
	numbers.reserve(100000);


	//you can change the capacity of the internal array if you have to. but you need to do that by reinitialising the vector with a new temporary vector
	// this is not something that you typically have to do
	const int newCapacity = 0;
	vector<double>(newCapacity).swap(numbers);

	cout << "Size: " << numbers.size() << endl;
	cout << "Capacity: " << numbers.capacity() << endl;


	return 0;
}
