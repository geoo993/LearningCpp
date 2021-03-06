//============================================================================
// Name        : StaticCast.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Film {

public:
	void print(){
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

	//ways of casting
	float fValue = 4.543;
	cout << (int)fValue << endl;//casting with the type in the front of the value
	cout << int(fValue) << endl;//casting with the value within the round brackets of the type

	//c++ gives you some more precise defined types of casting that can help reduce errors in your program, the simplest of those is the static cast
	cout << static_cast<int>(fValue) << endl;//here we also cast using static_cast, in the diamond brackets you put the cast you want



	Film film;
	Hostle hostle;

	Film *pFilm = &hostle;//this will work
	//Hostle *pHostle = &film;//this will not work
	//to force it to work, you can use static_cast
	Hostle *pHostle = static_cast<Hostle *> (&film);

	cout << pFilm << " " << pHostle << endl;

	cout << endl;

	Film *pHostle1 = &hostle;
	Hostle *pHostle2 = static_cast<Hostle *> (pHostle1);//casting to its own self, this is potentially very error prone
	cout << pHostle2 << endl;

	// so the thing to bear in mind is static_cast is not always safe to use, its just a compile time thing that will get your code to work.

	Film &&newFilm1 = Film();//this is calling an R value object,
	//what if you want this R value to refer to an L value reference
	Film &&newFilm2 = static_cast<Film &&>(film);//here we are casting n R Value reference to an L value

	newFilm1.print();
	newFilm2.print();

	return 0;
}
