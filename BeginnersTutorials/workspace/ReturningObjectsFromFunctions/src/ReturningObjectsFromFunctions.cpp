//============================================================================
// Name        : ReturningObjectsFromFunctions.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Book{

private:
	string title;
	string genre;
	string author;

public:
	Book(){ cout << "Book Created by Constructor..." << endl; };
	~Book(){ cout << "Book Disposed by Destructor..." << endl; };
	Book(const Book& other): title(other.title), genre(other.genre), author(author) { cout << "Book Created by copying..." << endl; };
	Book(string title, string genre, string author): title(title), genre(genre), author(author){}
	Book createBook(string title, string genre, string author);
	void setTitle(string title) { this -> title = title; };
	void setGenre(string genre) { this -> genre = genre; };
	void setAuthor(string author) { this -> author = author; };
	void print() const {
		cout << author << " book, " << title << " is a " << genre << "Book." << endl;
	};
};

Book createBook(string title="", string genre="", string author=""){
	return Book(title, genre, author);
}

Book *makeBook(){
	Book *pBook = new Book();
	pBook -> setTitle("Heaven is for Real ");
	return pBook;
}


int main() {


	Book *pNewBook = new Book();
	pNewBook->setTitle("The laws of Simplicity");
	pNewBook->setAuthor("John Maeda");
	pNewBook->setGenre("Educational");
	pNewBook->print();
	delete pNewBook;//delete is very very importer when you are creating a pointer to class or method, it deallocate the memory created by the new class created


	Book book = createBook();
	book.print();


	Book *pMadeBook = makeBook();
	pMadeBook->print();
	delete pMadeBook;


	return 0;
}
