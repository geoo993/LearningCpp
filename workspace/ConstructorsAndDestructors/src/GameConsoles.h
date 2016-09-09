/*
 * GameConsoles.h
 *
 *  Created on: Sep 7, 2016
 *      Author: GeorgeQuentin
 */

#ifndef GAMECONSOLES_H_
#define GAMECONSOLES_H_
#include <string>

class GameConsoles {
private:

	std::string name;
	std::string controller;
	std::string storage;
	double price;
	std::string releaseDate;

public:
	GameConsoles();//this is a constructor, contructors and destructors cant return a value
	~GameConsoles(); //this is a destructor, this runs when the object is destroyed, this has a tilde sign (~) in front of the Function name
	GameConsoles(std::string name, std::string controller, std::string storage, double price, std::string releaseDate);
	void setConsole(std::string name, std::string controller, std::string storage, double price, std::string releaseDate);
	void consoleInfo(std::string name);
	int stringToInt(std::string str);
	void print();
};

#endif /* GAMECONSOLES_H_ */
