//============================================================================
// Name        : LambdaExpressionsParametersAndReturnTypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;


void testGreet(string name, void ( *greet)(string) ){//creating and calling function pointer

	greet(name);
}

void runDivide(double aValue, double bValue, double (*pDivide)(double a, double b)  ){

	auto r = pDivide(aValue, bValue);

	cout << r << endl;
}


int main() {

	auto y = [] (auto first, auto second)
	{
	    return first + second;
	};

	auto x1 = [](int i){ return i; }; // OK: return type is int


	auto glambda = [](int a, int&& b) { return a < b; }; // returns a bool
	bool b = glambda(3, 3.14); // ok


	// generic lambda, operator() is a template with one parameter
	auto vglambda = [](auto printer) {
	    return [=](auto&&ts) // generic lambda, ts is a parameter pack
	    {
	        printer(forward<decltype(ts)>(ts));
	        return [=] { printer(ts); }; // nullary lambda (takes no parameters)
	    };
	};

	auto p = vglambda([](auto v1, auto v2, auto v3) { cout << v1 << v2 << v3; });



	auto pGreet = [](auto name){ cout << "name: " << name << endl; };

	pGreet("Geo");

	testGreet("Bod", pGreet);

	testGreet("Many Boxer", [](string name){ cout << "name: " << name << endl; });


	auto pDivide = [](double a, double b) -> double{//trailing return type

		if (b == 0.0){
			return 0;
		}
		return a/b;
	};

	double pie = pDivide(12.2538, 3.9);
	cout << pie << endl;

	runDivide(50, 343, pDivide );


	return 0;
}
