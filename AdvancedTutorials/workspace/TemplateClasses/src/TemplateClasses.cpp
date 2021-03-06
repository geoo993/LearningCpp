//============================================================================
// Name        : TemplateClasses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//one important thing about template classes, is that its not so easy to separate the implementation from the actual class
//what you usually do with a class is that you declare it outside the main function, and you kind of put the declaration of it in a header and you put the actual implementation in a cpp file
//with template classes, c++ has to see both the implementation and the definition/declaration all together before it can compile your code, because behind the scenes c++ is going to create the particular class involving particular types
//as templates can contain other elements or types, c++ is going to create the particular type, whether its a class, vector, list etc... behind the scenes and to do that it needs to see the implementation and definition all in one place
//so its better to define all your template files all in header files, normally you will put all your template files all in a header file and you would not use a cpp file, so you would declare all your implementation and definitions in the header file


//template classes allow you to design classes, that work with types of variables that the user can specify.
//take for example vector, which is a type of template class and also why it is a member of the standard template library
//template classes are not often useful in c++, but when they are useful, they can be really useful and they are not really that complicated


// you turn a class into a template class, you have to write the template above it
// now we create a template for the class bellow which is represented using C, which the user can use to specify the class
//you can change the C to any name you want, but its quite common to use single capital letter
template<class C>
class Test {

private:

	C obj1;

public:
	Test(C obj1){
		this ->obj1 = obj1;
	}
	~Test(){};

	void print(){
		cout << obj1 << endl;
	}

};
int main() {

	//the template class above allows us to use any template type  to declare a Test object
	Test<string> test1("Mauri");
	test1.print();

	cout << endl;

	Test<int> test2(20);
	test2.print();

	cout << endl;

	Test<double> test3(2950.40);
	test3.print();


	return 0;
}
