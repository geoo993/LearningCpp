//============================================================================
// Name        : Arithmetic.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


/*
 * +
 * -
 * *
 * /
 * +=  or ++
 * -=  or --
 * /=
 * *=
 * %
 * %=
 * (float)number, casting to flaot
 * (int)number, casting to int
 * (double)number, casting to double
 *
 * precedence
 */


int main() {

	float value1 = 7/2;//whenever you divide an integer with an integer it will always discard the remainder where in this case will give you 3
	float value2 = (float)7/2;// but if you cast it with float you will get the right number which in this case is 3.5;
	cout << "Value1: " << value1  << endl;
	cout << "value2: " << value2  << endl;

	// casting is often useful and you can use it to convert certain kings of types into certain kinds of similar types
	int value3 = 4.656; // the compiler will actually throw away the remainder and always give you 4,
	double value4 = (int)4.6;// you need to cast it with double to get the full value
	cout << "value3: " << value3  << endl;
	cout << "value4: " << value4  << endl;


	int value5 = 9;
	value5 += 1; // this is the same as or equivalent to (value5 = value5 + 1) or (value5 ++)
	cout << "value5: " << value5  << endl;

	int value6 = 16;
	value6 /= 4; // this is the same as or equivalent to (value6 = value6 / 4)
	cout << "value6: " << value6  << endl;


	int value7 = 41%6; // this is a modular formula, it does a division an gives you the remainder, it only stores and gives you the remainder of the modular formula/equation
	cout << "value7: " << value7  << endl;

	bool isTrueFalse = (125 % 5) == 3;// this is a modular boolean that checks if the remainder is true or false based on the condition (== 3) given
	cout << "bool answer: " << isTrueFalse  << endl;

	double equation1 = 2.4/6+2*9;// cpp will figure out the meaning of this by focusing on the * or / first. certain operator have a higher precedence than others where in this case * and / have a higher precedence or priority that + or -, meaning they will be done/solved first.
	double equation2 = (2.4/6)+(2*9);// same as euqation1, this is to show that * and / have a higher precedence than + or -

	cout << "equation1: " << equation1  << endl;
	cout << "equation2: " << equation2  << endl;

	return 0;
}
