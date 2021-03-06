//============================================================================
// Name        : DynamicCast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Film {

public:
	virtual void print(){
		cout << "Parent Film!" << endl;
	}

};

class Hostle: public Film {

};

class Oculus: public Film{

};

class Chucky: public Film{

};


int main() {

	Film film;
	Hostle hostle;

	Film *pFilm = &film;//you get invalid cast
	//Film *pFilm = &hostle;//the dynamic casting works

	//dynamic cast unlike static cast, is just a compile time thing, it checks types at run time to make sure you are doing something that makes sense, this will only work if you have Run Time Type Information (RTTI) turned on in the compiler
	Hostle *pHostle = dynamic_cast<Hostle *> (pFilm);

	if (pHostle == nullptr){
		cout << "Invalid Cast" << endl;
	}else{
		cout << pHostle << endl;
	}

	//bottom line is, if you can use dynamic cast, its better to use them than static cast because it will check things at run time and let you know if its safe to do so. static cast does not do this run time checking


	return 0;
}
