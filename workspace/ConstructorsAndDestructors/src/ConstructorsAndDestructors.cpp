//============================================================================
// Name        : ConstructorsAndDestructors.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "GameConsoles.h"
using namespace std;

int main() {

	cout << "Starting Program..." << endl << endl;


	//you can use open and closed curly bracket in program if you want, whatever things are assigned within the brackets will not be used outside of it
	{
		string name;

		do {

			cout << "Enter Console > " << flush;
			cin >> name;

			GameConsoles playstation;
			playstation.consoleInfo(name);

		} while (true);

	}
	cout << endl << "Ending Program..." << endl;
	return 0;
}
