//============================================================================
// Name        : CharArrays.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	string text = "hello";
	char texts1[] = {'h','e','l','l','o'}; // you can also store text in an array, char array in fact. the  char type is one byte long  and often used for storing characters from the ascii character set
	char texts2[] = "hello"; // this is the same as texts1 above, much simple in fact and can be called a primitive string as its using the string class

	cout << text << endl;

	cout << texts1 << endl;


	const char *chars = text.c_str();

	int lengthOfCharArray1 = strlen(chars); //using strlen gives you the correct size of the char array ;
	int lengthOfCharArray2 = sizeof(texts2);// this gives you the length of the array but has a +1 because we have a null terminator character in the array due to sizeof and also because it was added because of the double quotation mark used when initializing the array;

	cout << "Length of Array " << lengthOfCharArray2 << endl;

	for (int i = 0; i < lengthOfCharArray2; i++) {
		cout << i << ": " << texts2[i] << endl;
	}

	int j = 0;

	while(true){

		if (texts2[j] == 0){
			break;
		}
		cout << texts2[j] << flush;

		j ++;
	}

	return 0;
}
