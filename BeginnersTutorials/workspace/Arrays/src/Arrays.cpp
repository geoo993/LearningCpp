//============================================================================
// Name        : Arrays.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
using namespace std;

int main() {

	cout << "ARRAYS " << endl;
	cout << "=========== " << endl << endl;

	//Arrays are list of values
	double e[5] = {1000.4, 2.21, 34.9, 17.64, 50.5}; //e is an array of 5 doubles
	for ( unsigned int i = 0; i < sizeof(e)/sizeof(double); i++ )
	{
		cout <<	e[ i ] << " " << flush;
	}

	int j[] = {2, 3, 5, 7, 11, 13, 17, 19};// j is an array of no size but has 8 integer elements
	int f[50] = {20, 31, 18};   // f is an array of 50 integers but 47 trailing zeros are deduced
	int n[ 24 ]; // n is an array of 10 integers

	int arrayLength = sizeof(n)/sizeof(int);
	cout << endl << endl << "Array size: " << arrayLength << endl;

	//initializing n array
	for ( int i = 0; i < arrayLength; i++ )
	{
		n[ i ] = i * 12; // set element at location i to (i*12)
	}

	for ( int a = 0; a < arrayLength; a++ )
	{
		cout << "Element at index " << a << ": " << n[a] << endl;
	}


	string fruits[] = {"apple", "banana", "pear", "grape"};
	int stringArraylength =  sizeof(fruits)/sizeof(string);
	cout << "Fruit Array size: " << stringArraylength << endl;
	for ( int i = 0; i < stringArraylength; i++ )
	{
		if (fruits[i] == "pear"){
			continue;
		}
		cout << "Fruit at index " << i << " is: " << fruits[i] << endl;
	}


	cout << endl << "MULTIDIMENTIONAL ARRAYS " << endl;
	cout << "=========== " << endl << endl;

	string animals[2][3] = { // this array has two rows and three columns
		{"cobra", "black mamba", "anaconda"},// snakes
		{"lion","cheetah", "jaguar"}
	};

	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 3; j++ ){

			if (i == 0 && j == 1){
				cout << endl << "Animal at row " << i << " at index "<< j << " is: " << animals[i][j] << endl << endl;
			}

		}
	}


	int shirtNumber[][11] = {
		{2,5,78,9,10,21,20,10,16,28,4},
		{4,1,17,5,8,6,10,11,9,3,19},
		{12,4,1,21,18,7,10,8,9,3,11}
	};

	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 11; j++ ){
			cout << shirtNumber[i][j] << " "<< flush;
		}
		cout << endl;
	}

	cout << endl << "Size of String: " << sizeof(string) << endl;
	cout << "Size of shirtNumber array: " << sizeof(shirtNumber) << endl;

	int lengthOfShirtNumber = sizeof(shirtNumber)/sizeof(shirtNumber[0]);

	cout << endl << "Length of ShirtNumber Array: " << lengthOfShirtNumber << endl;

	for ( int i = 0; i < lengthOfShirtNumber; i++ )
	{
		cout << "Length of Sub ShirtNumber Array: " << sizeof(shirtNumber[0])/sizeof(int) << endl;

		for ( int j = 0; j < sizeof(shirtNumber[0])/sizeof(int); j++ )
		{
			cout << shirtNumber[i][j] << " "<< flush;
		}
		cout << endl;
	}

	return 0;
}
