//============================================================================
// Name        : TemplateFunctions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

//you can mix and add multiple types in template classes
template<class C, class K>
class Test {

private:

	C obj1;
	K obj2;

public:

	Test(C obj1, K obj2): obj1(obj1), obj2(obj2) {}
	~Test(){};

	void print(){
		cout << obj1 << ": " << obj2 << endl;
	}

};


//Suppose you want to make this function take any type at all, you need to make it pass in a template
void show(int i){
	cout << "Show without template: " << i << endl;
}


// you do not have to use class, you can also use typename. this works with both classes and functions
//most people prefer typename because its kind of clarifies what you should do whereby it tell you what to insert which is a typename such as int, double
//template<class T>
template<typename T>
void show(T i){// we overridden the show function above, you must include the template class in the argument list which in this case is (T i)
	cout << "Show using template: "<< i << endl;
}


template<typename T>
void show(){
	cout << "Template without argument list. This is not great..."<< T() << endl;
}

int main() {

	Test<string, int> test1("Mauri", 23);
	test1.print();

	cout << endl;


	//PRINTING WITHOUT USING TEMPLATE
	show(24);

	//PRINTING WITH TEMPLATE
	show<string>("Hello");
	show<double>(23.1);
	show<float>(0.234);
	show<char> ('V');
	show<bool> ((rand() % 5)>2);

	show('J');
	show(2408);
	show(21.7);


	// you have to put in at least the diamond brackets (<>) for c++ to acknowledge that we want to use the template version
	show<>(2036);

	//template function with no argument list
	show<double>();

	return 0;
}
