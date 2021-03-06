//============================================================================
// Name        : ParsingTextinFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	string fileName = "stats.txt";

	ifstream input;
	input.open(fileName);

	if (!input.is_open()){
		return 1;
	}

	while (input){
		string line;


		//get line allows us to supply delimiter, meaning separators, were it will read the file up to the delimiter that you gave. Then the delimiter will be thrown away
		//you have to use single quotes, because you use a single to create a single literal character, which is different from string
		getline(input, line, ':');

		long int population;
		input >> population;

		//we need to remove the non printing line characters found in the file that we are reading
		//discarding the return characters left such as spaces or new lines. we use get which gets all the other bits of characters found in the text file
		input.get();

		//this is something you can do in c++ 11 which reads what ever white space there is in the file, it Discards leading whitespace from an input stream.
		//its a little bit more of a robust solution to get white spaces
		//input >> ws;

		// check if we got an error or figure out if we in an error condition and then break out of the loop
		if(!input){
			break;
		}

		cout << "'" << line << "'" << "--" << "'" << population << "'" << endl;

	}


	input.close();

	return 0;
}
