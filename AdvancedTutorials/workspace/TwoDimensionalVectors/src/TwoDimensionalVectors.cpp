//============================================================================
// Name        : TwoDimensionalVectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main() {


	//A grid system is a great example of two dimensional array or vectors
	// to create a grid you have to have vectors of vectors

	const int value = 5;
	vector < vector< int> > grid(4, vector<int>(8, value));// here we are pre-sizing the grid with 4 rows and each row has 8 elements with a value called value

	grid[2].push_back(2);

	int add = 0;

	//you can iterate through this vector using a 2D array
	for (int row = 0; row < grid.size(); row++){

		for (int col = 0; col < grid[row].size(); col++){

			grid[row][col] = add;
			add++;

			cout << grid[row][col] << ", " << flush;
		}

		cout << endl;

	}

	return 0;
}
