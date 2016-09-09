#include <iostream>
using namespace std;
//standard


//int main is a function that does something
int main() {
	//c out and end line
	//endl forces operating system to output the text
	cout << "Starting C++ program..." << flush; //flush tells operating system to output this text but doesnt create a new line like endl
	cout << "Hello Everyone!" << endl;
	cout << "this is sexy text = with endl." << endl;

	cout << " The world of WarCraft" << endl;
	cout << "Fruit list: " << "Apple." << "Banana." << "Pear." << endl;
	cout << "Console list: " << " " << "Nintendo" << " " << "PlayStation" << " " << "Xbox" << endl;

	cout << "this is risky text = no endl.";//when there is no flush or endl, there is no garranty that the text will be outputted or shown
	return 0;
}
