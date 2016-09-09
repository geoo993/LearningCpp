/*
 * Countries.h
 *
 *  Created on: Sep 6, 2016
 *      Author: GeorgeQuentin
 */



#ifndef COUNTRIES_H_
#define COUNTRIES_H_
#include <string>

class Country {

private:
	std::string countryName;
	std::string capital;
    long int population;
    std::string nationalLanguage;
    std::string currency;


public:
    Country();
    Country(std::string countryName, std::string capital, long int population, std::string nationalLanguage, std::string currency);
    void setCountry(std::string countryName, std::string capital, long int population, std::string nationalLanguage, std::string currency);
    int stringToInt(std::string str);
    void countryInfo(std::string name);
    std::string getCountryName();
    std::string getCapital();
    long int getPopulation();
    std::string getNationalLanguage();
    std::string getCurrency();
    void print();


//
};

#endif /* COUNTRIES_H_ */
