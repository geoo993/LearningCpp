//============================================================================
// Name        : ReadingTextFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

//reading text files works very similarly with writing text files.

int main() {

	string inFileName = "rooneyFile.txt";

	ifstream inFile;
	inFile.open(inFileName);


//	fstream inFile;
//	inFile.open(inFileName, ios::in);


	if (inFile.is_open()){

		// reading lines from the file
		string line;
		//inFile >> line;// here we get the first word on first line in the file
		//getline(inFile, line);//here we get the first line in the file

		//while(!inFile.eof())// while not in eof(end of file)
		while(inFile)
		{
			getline(inFile, line);// reading all lines in file, using while loop
			cout << line << endl;
		}


		inFile.close();
	}else{
		cout << "Cannot open file: " << inFileName << endl;
	}


	return 0;
}
