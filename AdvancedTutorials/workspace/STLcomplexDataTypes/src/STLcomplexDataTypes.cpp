//============================================================================
// Name        : STLcomplexDataTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	//STL complex, nested data types. you can use any nested Standard Template Library types to represent any data structure, no matter how complex it is

	//vector < map<int> > ids;

	map < string, vector<int> > scores;

	scores["Ela"].push_back(22);
	scores["Yousuf"].push_back(17);
	scores["Daniel"].push_back(35);
	scores["Daniel"].push_back(17);
	scores["Simba"].push_back(25);
	scores["Zelda"].push_back(23);

	for (map<string, vector<int> >::iterator it = scores.begin(); it != scores.end(); it++)
	//for (auto it = scores.begin(); it != scores.end(); it++)
	{
		string name = it->first;
		vector<int> scoreList = it->second;

		cout << "name: " << name << flush;

		for (int i = 0; i < scoreList.size(); i++){
			cout << ", score: " << scoreList[i] << " " << flush;
		}

		cout << endl;
	}



	return 0;
}
