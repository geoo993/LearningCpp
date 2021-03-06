//============================================================================
// Name        : CopyConstructors.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Game{

private:
	string title;
	string genre;
	string dev;
	string platform;

public:
	Game(){ cout << "Game Created by Constructor..." << endl; };
	~Game(){ cout << "Game Disposed by Destructor..." << endl; };
	Game(const Game& other): title(other.title), genre(other.genre), dev(other.dev), platform(other.platform) { cout << "Game Created by copying..." << endl; };// this here, we are defining a copy constructor
	Game(string title, string genre, string dev, string platform): title(title), genre(genre), dev(dev), platform(platform){}
	void setTitle(string title) { this -> title = title; };
	void setGenre(string genre) { this -> genre = genre; };
	void setDeveloper(string dev) { this -> dev = dev; };
	void setPlatform(string platform) { this -> platform = platform; };
	void print() const {
		cout << dev << " made " << genre << " game, " << title << " for the " << platform << endl;
	};
};

int main() {

	Game game1("Fifa 17", "Sport", "EA Sports", "PlayStation 4");


	Game game2 = game1;// here, we are invoking a copy of the first instructor (game1) meaning that this constructor (game2) is just a reference to the first constructor (game1)
	game2.setTitle("NBA 17");

	game1.print();
	game2.print();

	Game game3(game2);// another way of copying a valid constructor
	game3.setTitle("Halo 4");
	game3.setDeveloper("Bungie");
	game3.setGenre("Action/Adventure");
	game3.setPlatform("Xbox One");
	game3.print();


	Game game4(game3);
	game4.setTitle("Uncharted 4: A Thief's End");
	game4.setDeveloper("Naughty Dogs");
	game4.setPlatform("PlayStation 4");
	game4.print();



	//there's another way of instantiating another object from a class

	Game *pGame = new Game();// the new operator allocates memory explicitly, memory which you actually manage your self. in this case its allocating memory for a single (game) object. the round brackets () are optional so you can put them in or not put them in, maybe unless you want to add parameters in brackets
	//Game *pGame = new Game;// same as above without round brackets

	(*pGame).setTitle("Doom");
	(*pGame).print();

	Game *pNewGame = new Game;
	pNewGame->setTitle("Resident Evil 7");// adding the arrow now makes the memory for this new pointer object to not be destroyed/destructed by the destructor. you have to call delete to make sure that the destructor happens
	pNewGame->setDeveloper("Capcom");
	pNewGame->setGenre("Horror");
	pNewGame->setPlatform("Microsoft Windows");
	pNewGame->print();
	delete pNewGame;// delete will deallocate the memory that this pointer has

	//Game *pOldGame = NULL;//can also set pointers to null when creating them.

	cout << "Pointer Size = "<< sizeof(pNewGame)<< "; Long int Size = " << sizeof(long) << endl;//the size of a pointer is actually the same as a long int
	return 0;
}
