//============================================================================
// Name        : BreakAndContinue.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	/* BREAK.....
	 * break stops the for loop from continuing looping by stopping the loop when the condition of the break is true

	 for (int i=0; i < 10; i++){
	 cout << "Hello " << i << endl;

	 if (i==3)
	 {
	 cout << "Loop stops with Break at" << i << endl;
	 break;
	 cout << "Check if loop is continuing " << endl;
	 }

	 cout << "Looping " << endl;

	 }
	 */

	/*CONTINUE
	//continue stops the loop temporarily, it does not execute any code after the continue statement and only does this when the condition of the continue is true. continue only happens at a particular loop of a for loop meaning it does not run on every loop unless specified
	for (int i = 0; i < 10; i++) {
		cout << "Hello " << i << endl;

		if (i == 6) {
			cout << "stopped looping because of continue " << endl;
			continue;
			cout << "Check if loop is continuing " << endl;
		}

		cout << "Looping " << endl;

	}
	*/

	const string password = "george";
	string input;
	do {

		cout << "Enter Password > " << flush;

		cin >> input;

		if (input == password) {
			cout << "Password Correct " << "'"<< input << "'" << endl;
			break;
		} else {
			cout << "Invalid Password " << "'"<< input << "'" << endl;
		}

	}while (true);

	cout << "Program quitting" << endl;

	return 0;
}
