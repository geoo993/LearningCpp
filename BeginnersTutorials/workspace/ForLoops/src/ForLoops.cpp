//============================================================================
// Name        : ForLoops.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <string>
using namespace std;

int main() {

	//for(;;){}// this is an empty active loop

	//in first section you declare a variable (int i = 0) which is going to be used for condition checks in second section and as a the loop counter in third section
	//in second section you put a condition (i < 10) which often involves the variable assigned in section one, the for loop will only be executed when this condition is true
	//in third section you input the amount of times the variable is incremented by which is often incremented up by one (i++), or you can increment down (i--)


	for(int i=0; i < 10; ++i) {
		cout << "Number of Loops " << i << endl;
	}


	int i = 0;
	do {

		cout << "Number of do iterations " << i << endl;
		i++;
	}while (i<10);



	return 0;
}
