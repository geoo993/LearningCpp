/*
 * Countries.cpp
 *
 *  Created on: Sep 6, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <map>
#include "Countries.h"
#include <string>

using namespace std;

//enum countryN {
//	Brazil,
//	Cameroun,
//	France,
//	Italy,
//	Spain,
//	Nigeria,
//	England,
//	UnitedStates,
//	China,
//	Australia
//};
//map<string, countryN> countriesList;
//
//
//
//void initializeCountries()
//{
//
//	countriesList["Brazil"] = Brazil;
//	countriesList["Cameroun"] = Cameroun;
//	countriesList["France"] = France;
//	countriesList["Italy"] = Italy;
//	countriesList["Spain"] = Spain;
//	countriesList["Nigeria"] = Nigeria;
//	countriesList["England"] = England;
//	countriesList["United States"] = UnitedStates;
//	countriesList["China"] = China;
//	countriesList["Australia"] = Australia;
//
//}

//std::string CountriesClass::countryName(std::string countryName) {
//
//	initializeCountries();
//
//	switch (countriesList[countryName])
//	{
//	case Brazil:
//		return "Brazil";
//		break;
//	case Cameroun:
//		return "Cameroun";
//		break;
//	case France:
//		return "France";
//		break;
//	case Italy:
//		return  "Italy";
//		break;
//	case Spain:
//		return  "Spain";
//		break;
//	case Nigeria:
//		return  "Nigeria";
//		break;
//	case England:
//		return "England";
//		break;
//	case UnitedStates:
//		return "United States";
//		break;
//	case China:
//		return  "China";
//		break;
//	case Australia:
//		return  "Australia";
//		break;
//	default:
//		return "We do not have this country in our selection";
//
//	}
//}


Country::Country() {
	countryName = "";
	capital = "";
	population = 0;
	nationalLanguage = "";
	currency = "";
}

Country::Country(std::string countryName, std::string capital,
		long int population, std::string nationalLanguage, std::string currency) {
	this -> countryName = countryName;
	this -> capital = capital;
	this -> population = population;
	this -> nationalLanguage = nationalLanguage;
	this -> currency = currency;
}

void Country::setCountry(std::string countryName, std::string capital,
		long int population, std::string nationalLanguage, std::string currency) {
	this -> countryName = countryName;
	this -> capital = capital;
	this -> population = population;
	this -> nationalLanguage = nationalLanguage;
	this -> currency = currency;
}

std::string Country::getCountryName() {
	return countryName;
}

std::string Country::getCapital() {
	return capital;
}
long int Country::getPopulation() {
	return population;
}
std::string Country::getNationalLanguage() {
	return nationalLanguage;
}
std::string Country::getCurrency() {
	return currency;
}

void Country::print() {
	cout << "Country Name : " << countryName << endl;
	cout << "Country Capital : " << capital << endl;
	cout << "Country Population : " << population << endl;
	cout << "Country National Language : " << nationalLanguage << endl;
	cout << "Country Currency : " << currency << endl;
}

int Country::stringToInt(std::string str) {

	const char* characters = str.c_str();

	int value = 0;
	for (int i = 0; i < strlen(characters); i++) {
		value = value + (int) characters[i];
	}

	return value;
}

void Country::countryInfo(std::string name) {

	int countryNum = stringToInt(name);

	switch (countryNum) {
	case 612:
		setCountry("Brazil", "Brasília", 210135000, "Portuguese",
				"Brazilian Real R$");
		break;
	case 820:
		setCountry("Cameroon", "Yaoundé", 24032000, "French, English",
				"Central African CFA franc");
		break;
	case 591:
		setCountry("France", "Paris", 64745000, "French", "Euro €");
		break;
	case 515:
		setCountry("Italy", "Rome", 59864000, "Italian", "Euro €");
		break;
	case 507:
		setCountry("Spain", "Madrid", 46029600, "Spanish", "Euro €");
		break;
	case 703:
		setCountry("Nigeria", "Abuja", 187918000, "English", "Naira ₦");
		break;
	case 697:
		setCountry("England", "London", 65185000, "English", "Pound Sterling £");
		break;
	case 1245:
		setCountry("United States", "Washington", 324678000, "English",
				"United States Dollar $");
		break;
	case 483:
		setCountry("China", "Beijing", 1380147000, "Chinese Mandarin",
				"Renminbi ¥");
		break;
	case 934:
		setCountry("Australia", "Canberra", 24423000, "English",
				"Australian dollar $");
		break;
	case 568:
		setCountry("Canada", "Ottawa", 36387900, "English, French",
				"Canadian Dollar $");
		break;
	case 490:
		setCountry("Japan", "Tokyo", 126432000, "Japanese", "Japanese Yen ¥");
		break;
	case 644:
		setCountry("Turkey", "Ankara", 80311900, "Turkish", "Turkey Lira ₺");
		break;
	case 631:
		setCountry("Russia", "Moscow", 146371000, "Russian", "Russia Ruble руб");
		break;
	case 485:
		setCountry("India", "New Delhi", 1330831000, "Hindi", "India Rupee ₹");
		break;
	case 723:
		setCountry("Germany", "Berlin", 81283700, "German", "Euros €");
		break;
	case 1817:
		setCountry("United Arab Emirates", "Abu Dhabi", 9412000,
				"Arabic, English", "Emirati Dirham د.إ");
		break;
	case 1113:
		setCountry("South Africa", "Pretoria", 55218000, "Afrikaans, English",
				"South Africa Rand R");
		break;
	case 922:
		setCountry("Indonesia", "Jakarta", 261525000, "Indonesian",
				"Indonesia Rupiah Rp");
		break;
	case 613:
		setCountry("Mexico", "Mexico City", 129112000, "Spanish",
				"Mexico Peso $");
		break;
	case 1078:
		setCountry("Saudi Arabia", "Riyadh", 32431100, "Arabic",
				"Saudi Arabic: ريال riyāl");
		break;
	case 921:
		setCountry("Argentina", "Buenos Aires", 43953600, "Spanish",
				"Argentine Peso $");
		break;
	case 1001:
		setCountry("New Zealand", "Wellington", 4566000, "English",
				"New Zealand Dollar $");
		break;
	case 608:
		setCountry("Israel", "Jerusalem", 8225900, "Hebrew, Arabic",
				"Israel Shekel ₪");
		break;
	case 379:
		setCountry("Cuba", "Havana", 11412000, "Spanish", "Cuba Peso ₱");
		break;
	default:
		countryName = "We do not have this country in our selection";
		capital = "No Capital City for this selection";
		population = 0;
		nationalLanguage = "No Language for this selection";
		currency = "No Currency for this selection";

	}

	print();

}

