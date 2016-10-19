//============================================================================
// Name        : TestCpp11.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<int> list = {1,34,56,7,89,64,22};


int main() {

	for(auto i : list)
	{

		cout << i << endl;
	}

	return 0;
}
