//============================================================================
// Name        : ElisionAndOptimization.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;


class Test{
private:
	int id{2};
	string name = "Aio";


public:

	Test(): Test(12, "Jon"){//using another constructor
		cout << "No Parameters in Constructor" << endl;
	}

	Test(string name){
		this -> name = name;
		cout << "String Parameter in Constructor" << endl;
	}

	Test(int id, string name): id(id), name(name){//parameters constructor
		cout << "Int and String Parameter in Constructor" << endl;
	}

	Test(const Test &other) = default;// copy constructor

	Test &operator=(const Test &other) = default;//assignment constructor

	void setId(int id){
		this -> id = id;
	}

	void setName(string name){
		this -> name = name;
	}

	void print(){
		cout << id << ": " << name << endl;
	}

	~Test(){//destructor
		cout << "Destructor" << endl;
	}


	// the put to (<<) operator, so you can use objects of this class with cout
	friend ostream &operator<<(ostream &out, const Test &test);

};


ostream &operator<<(ostream &out, const Test &test){
	out << "Hello from test put to operator";
	return out;
}

Test getTest(){

	// c++ 98 does return value optimisation, which involves getting rid of extra copies of objects
	return Test();
}



int main() {

	Test test4 = getTest();// we are doing a copy initialisation
	cout << test4 << endl;// the ostream operator allows us to use the class object in the cout
	test4.print();

	vector<Test> vec;
	vec.push_back(Test());


	return 0;
}
