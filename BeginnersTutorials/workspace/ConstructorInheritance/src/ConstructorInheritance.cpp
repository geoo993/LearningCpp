//============================================================================
// Name        : ConstructorInheritance.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// constructors are not inherited in cpp, you cannot call constructors of a supper class, but cpp will always run one of the constructors of supper classes when you instantiate an object from that class
class Machine{

private :
	int id;
	string name;
	string manufacturer;
public:
	Machine(int id): id(id) { cout << "Machine parameterized constructor is called." << endl; };
	Machine(string name, string manufacturer): name(name), manufacturer(manufacturer) { };
	string getMachineName(){ return name; }
	string getMachineManufacturer(){ return manufacturer; }
	void machineInfo(){ cout << "Machine ID: " << id << endl; };
};

// at each step of the hierarchy of the inherited classes, you are allowed to specify which constructor will be called in the supper class
class Vehicle: public Machine {

public:
	//this is the class constructor of Vehicle which is a subclass of machine
	Vehicle( string name="", string manufacturer=""): Machine(name,manufacturer) {// here we are passing in the parameters of Machine class to the vehicle Class constructor. this an example of constructor inheritance
		cout << "Vehicle parameterized constructor called. It is the sub class Machine" << endl;
	}
	string getName(){ return getMachineName(); }
	string getManufacturer(){ return getMachineManufacturer(); }
	void info(){cout << getName() <<  " is manufactured by " << getManufacturer() << endl;}
};

class Car: public Vehicle{


	//this is a sub class of the Vehicle class
public:
	Car(){ cout << "This is the Vehicle Car constructor." << endl;}
};


int main() {

	Machine machine(234);
	machine.machineInfo();

	// this vehicle class is based on the machine class
	//Vehicle vehicle("Airplane", "Boeing");
	//vehicle.info();

	//this car class is based on the vehicle class, it is a sub class of vehicle class where when called it will run the super class first which is Vehicle and then run its self
	//this car subclass cannot assess the private instances in the vehicle super class
	Car car;
	car.info();

	return 0;
}
