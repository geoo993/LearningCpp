//============================================================================
// Name        : ReversingString.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// reversing a primitive string

string reverseString(char cTexts[]){

	char *pStart = cTexts;

	int numberOfCharacters = strlen(cTexts); //or sizeof(texts)-1;
	char *pEnd = cTexts + numberOfCharacters - 1; // or &texts[numberOfCharacters-1];


	while (pStart < pEnd){
		//here we are reversing the texts char array using save and putting back on pEnd
		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart ++;
		pEnd --;
	}

	return (string)cTexts;
}


int main() {

	char texts[] = "hello George";
	cout << texts << endl;
	cout << "reverse string: " << reverseString(texts) << endl;

	return 0;
}
