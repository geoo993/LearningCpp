
#include <iostream>
#include <string>

using namespace std;//standard


float hello(){

	return 0.0;
}

string myString(string correctString)
{
    return correctString;
}

int addition (int a, int b)
{
  int result;
  result =a+b;
  return result;
}


int main() {

	int addResult = addition (15,10);
	std::string s = to_string(addResult);

	string str2 = " years old. Welcome to the World of C++";

	cout << "Hello George!, you are "+ s + str2 +myString(". Great!") << endl; // prints !!!Hello George!!!

	return 0;
}
