//============================================================================
// Name        : CatchingSubclassExceptions.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>

using namespace std;

void goesWrong() {

	bool errorDetected = false;
	bool error1Detected = false;
	bool error2Detected = true;
	bool error3Detected = true;
	bool error4Detected = true;
	bool error5Detected = true;


	if (error1Detected) {
		throw bad_alloc();
	}

	if (error2Detected) {
		throw domain_error( "Your domain is in error!" );
	}

	if (error3Detected) {
		throw bad_cast();
	}

	if (error4Detected) {
		throw overflow_error("Run Time Error, Objects OverFlow!");
	}

	if (error5Detected) {
		throw bad_typeid();
	}

	if (errorDetected) {
		throw exception();
	}

}

int main() {


	try {
		goesWrong();
	}
	//because this exception is the first catch, it will catch any error messages thrown above, this is because of polymorphism because exception is the supper class of all the excepting and it has the  functions that all the other exceptions are using
//	catch (exception &e) {
//		cout << "Catching Any Exception Message: " << e.what() << endl;// "what" here is a virtual polymorphism method that starts in exception class and also used in the exception subclasses
//	}


	catch (bad_alloc &e) {
		cout << "Bad Alloc Exception Message: " << e.what() << endl;
	}
	catch(domain_error &e){
		cout << "Domain Error message: " << e.what() << endl;
	}
	catch(bad_cast &e) {
		cout << "Bad Cast Exception Message: " << e.what() << endl;
	}
	catch(bad_typeid &e){
		cout << "Bad TypeID Error message: " << e.what() << endl;
	}
	catch(overflow_error &e){
		cout << "OverFlow Error message: " << e.what() << endl;
	}


	cout << "Still Running..." << endl;

	return 0;
}
