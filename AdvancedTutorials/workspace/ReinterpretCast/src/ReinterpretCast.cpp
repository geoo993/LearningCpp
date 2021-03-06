//============================================================================
// Name        : ReinterpretCast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Film {

public:
	virtual void print() {
		cout << "Film is the Parent Class!" << endl;
	}

};

class Hostle: public Film {

};

class Oculus: public Film {

};

class Chucky: public Film {

};

int main() {

	Film film;
	Hostle hostle;
	Oculus oculus;
	Chucky chucky;

	Film *pFilm1 = &hostle;
	Oculus *pOculus = dynamic_cast<Oculus *> (pFilm1);//casting Oculus to Hostle which are both subclasses of Film supper class, this will be invalid
	Chucky *pChucky = static_cast<Chucky *> (pFilm1);//this will be valid

	if (pOculus == nullptr) {
		cout << "Invalid pOculus Cast" << endl;
	} else {
		cout << pOculus << endl;
	}

	if (pChucky == nullptr) {
		cout << "Invalid pChucky Cast" << endl;
	} else {
		cout << pChucky << endl;
	}

	//bottom line, these types of casting are really silly to do, avoid doing this
	//what you can do is use reinterpret_cast, and what it does is that it kind of got less checking in it than static cast, will will most certainly cast things for you even when they seem wrong
	//reinterpret cast just does a binary cast of one pointer type to another, pretty much cast anything to anything
	Hostle *pHostle = reinterpret_cast<Hostle *> (pFilm1);//generally its best to avoid using reinterpret_cast
	if (pHostle == nullptr) {
		cout << "Invalid pHostle Cast" << endl;
	} else {
		cout << pHostle << endl;
	}

	return 0;
}
