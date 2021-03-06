//============================================================================
// Name        : WritingTextFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// streams are objects that we can read or write data from

#include <iostream>
#include <fstream>//file stream

using namespace std;

int main() {

	string outputFilename = "newtextFile.txt";

	//ofstream outFile; instead of ofstream(out file stream), we could also use fstream
	fstream outFile;


	//outFile.open(outputFilename);
	outFile.open(outputFilename, ios::out);// if we use fstream(file stream) and not the ofstream(out file stream). then we must specify that it is an output file in the second parameter, by supplying the argument ios::out

	if(outFile.is_open()){
		//in a file, you do not need to use flush to stick to the line, but you can use endl to go to the next line
		outFile << "Hello World !!!!!" << endl;
		outFile << "This is a new Line" << endl;

		outFile << 38484 << endl;//you can also write a number in the file in this form
		outFile << "ios::out still works" << endl;
		outFile.close();//always remember to use close the finish writing to file and close file

	}else{

		//handle exception here when file does not open
		cout << "Could not create file " << outputFilename << endl;

	}

	return 0;
}
