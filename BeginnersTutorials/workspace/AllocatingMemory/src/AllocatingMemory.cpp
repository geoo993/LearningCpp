//============================================================================
// Name        : AllocatingMemory.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Film{

private:
	string title;

public:
	Film(){ cout << "Film Created by Constructor..." << endl; };
	~Film(){ cout << "Film Disposed by Destructor..." << endl; };
	Film(const Film& other): title(other.title) { cout << "Film Created by copying..." << endl; };
	Film(string title): title(title){}
	void setTitle(string title){ this -> title = title; };
	void print() const {
		cout << title << " is a great film " << endl;
	};
};


int main() {

	//you can use new on any type at all, like int, long, double, float, classes, functions to allocate and initialize objects. So don't forget to use delete to deallocate memory when you created new
	Film *pFilm = new Film();
	delete pFilm;// you deallocate memory when method/class created has new

	//you can allocate memory of primitive types with new as well, never forget to delete after.
	float *pValue = new float();
	//long *pValue = new long();
	//double *pValue = new double();
	//string *pValue = new string();
	//int *pValue = new int();
	delete pValue;// you can deallocate memory of  primitive type that have new as well new well

	//you can also allocate memory with array of primitive types or objects
	const int AMOUNTOFFILMS = 10;
	Film *pFilms = new Film[AMOUNTOFFILMS];
	pFilms[4].setTitle("The Words");
	pFilms[4].print();
	delete [] pFilms;// you deallocate memory of array of objects like this, you are telling cpp that you are not deleting one object but you are actually deleting an array

	char *pChar = new char[1200];
	delete [] pChar;


	char c = 'a';

	string name(1, 'a'); //this is setting strings via characters, describing the order in which characters are allocated in string. this says create a string that has one character in it
	string name2(5, c);//or you can use the char for the string
	cout << name << endl;
	cout << name2 << endl;

	c++;// incrementing to get the next character in the ascii table
	string name3(1, c);
	cout << name3 << endl;

	return 0;
}
