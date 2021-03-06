//============================================================================
// Name        : ReadingAndWritingStructBinaryFiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {

	char name[50];
	int age;
	double weight;
	double height;

};
#pragma pack(pop)

void writeBinaryFile(Person &p, string &fileName) {

	ofstream ouputFile;//output file
	ouputFile.open(fileName, ios::binary);

	//fstream ouputFile;
	//ouputFile.open(fileName, ios::binary|ios::out);//if you're using fstream you need to include ios:out as well

	if (ouputFile.is_open()) {

		//ouputFile.write((char *)&p, sizeof(p));
		ouputFile.write(reinterpret_cast<char *> (&p), sizeof(Person));//different way of casting using reinterpret_cast

		ouputFile.close();

	} else {

		cout << "Could not create file: " + fileName << endl;
	}

}

void readBinaryFile(Person &p, string &fileName)  {

	ifstream inputFile;// input file
	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {

		inputFile.read(reinterpret_cast<char *> (&p), sizeof(Person));//different way of casting using reinterpret_cast

		inputFile.close();

	} else {

		cout << "Could not Read file: " + fileName << endl;
	}

}

int main() {

	Person p = { "Geo", 23, 123.4, 5.11 };
	Person p2 = { };

	string fileName = "test.bin";// bin for binary file

	//WRITE BINARY FILE //////////////
	writeBinaryFile(p, fileName);

	//READ BINARY FILE //////////////
	readBinaryFile(p2, fileName);

	cout << p2.name << ", " << p2.age << ", " << p2.weight << ", " << p2.height
			<< "." << endl;

	return 0;
}
