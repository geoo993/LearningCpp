/*
 * GameConsoles.cpp
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include "GameConsoles.h"
#include <string>

using namespace std;


GameConsoles:: GameConsoles(){

	cout << "Checking Console...." << endl;

	name = "";
	controller = "";
	storage = "";
	price = 0.0;
	releaseDate = "";

}

GameConsoles:: ~GameConsoles(){
	cout << "Stop Checking Console...." << endl;
}

GameConsoles::GameConsoles(std::string name, std::string controller, std::string storage, double price, std::string releaseDate){
	this -> name = name;
	this -> controller = controller;
	this -> storage = storage;
	this -> price = price;
	this -> releaseDate = releaseDate;
}

void GameConsoles::setConsole(std::string name, std::string controller, std::string storage, double price, std::string releaseDate){
	this -> name = name;
	this -> controller = controller;
	this -> storage = storage;
	this -> price = price;
	this -> releaseDate = releaseDate;
}
void GameConsoles::print() {
	cout <<endl << "Console Name : " << name << endl;
	cout << "Console Controller : " << controller << endl;
	cout << "Console Storage Capacity : " << storage << endl;
	cout << "Console Price : " << price << endl;
	cout << "Console Release Date : " << releaseDate << endl << endl;
}


int GameConsoles::stringToInt(std::string str) {

	const char* characters = str.c_str();

	int value = 0;
	for (int i = 0; i < strlen(characters); i++) {
		value = value + (int) characters[i];
	}

	return value;
}

void GameConsoles::consoleInfo(std::string consoleName) {

	int consoleNum = stringToInt(consoleName);

	switch (consoleNum) {
	case 1196:
		setConsole("PlayStation 4", "DualShock 4", "1 TB", 299.99,
				"November 29, 2013");
		break;
	case 1525:
		setConsole("Nintendo Wii Mini", "Wii Remote Plus", "512 MB", 89.99,
				"November 17, 2013");
		break;
	case 790:
		setConsole("Xbox One S", "Xbox One Controller", "1 TB or 2 TB", 489.95, "2nd August 2016");
		break;
	default:
		name = "We do not have this console in our selection";
		controller = "No Controller for this selection";
		storage = "no storage for this selection";
		price = 0.0;
		releaseDate = "No release date for this selection";

	}

	print();

}
