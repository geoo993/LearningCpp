//============================================================================
// Name        : TestExamplePaperRetry.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <initializer_list>
#include <list>
using namespace std;

/*
class Time {

public :
	Time(){
		cout << "Time constructor" << endl;
	}
};


class Appointment : public Time {
	string description;
	Time startTime;
	Time endTime;

public :
	Appointment(): description({}){
		cout << "Appointment constructor" << endl;
	}
	Appointment(const string & description, const Time & startTime, const Time & endTime):
		description(description), startTime(startTime), endTime(endTime){

	}

	friend ostream &operator<<(ostream &out, const Time &other) {

		return out << other.get_description() << ": " <<
				other.get_start_time() << "-" << other.get_end_time();
	}

	const string get_description() const { return description; }
	const Time get_start_time() const { return startTime; }
	const Time get_end_time() const { return endTime; }

};

class Diary : Appointment {

	list <Appointment> appointments;

public:
	Diary(): appointments({}){
		cout << "Dairy constructor" << endl;
	}

	Diary(initializer_list<Appointment> &new_appointment){

		for (auto app : new_appointment){
			appointments.push_back(app);
		}

	}

	void add(const Appointment &app){
		appointments.push_back(app);
	}

	int number_of_appointments () const
	{
		return appointments.size();
	}

	void print (const Time &other){
		for (auto app : appointments){
			cout << app << endl;
		}
	}

};


//Diary d1;  here we are initalising a Diary object with its defualt constructor, which also goes up the hierachy and generates an Appointment object and Time object three times.
//Dairy d2 = d1; here d2 is intiatlised using the member wise copy operator, which copied the d1 object is then destroys it. the program genreted the copy constructor automatically even when we have not specified or defined it
//Diary d3; is similar to d1 initalisation using the default constructor
//d3 = d2 here d3 is assigned to d2, d2 is overridden using the memberwise assingment, which is take a copy d2 into d3. which then desroyes the object
//the curly braces destroys all the object in reverse order calling their destructor as we are gone of scope




// this is a pure virtual member method, meaning it is an undefined method of an abstract class which can only be defined and overriden by any derived classes of this abstract class.
//the class is an abstarct class meaning, so it can never be defined or instantiated but can be used as a type and any of its sub classes


double values (const list <double> &a){
	double result = 0.0;

	for (list <double>::iterator it = a.begin(); it != a.end(); ++it){
		result = result + *it;
	}

	return result;
}


template <typename Iterator>
int distance (Iterator &first, const Iterator &last){

	int count = 0;
	while (first != last && last > first){
		++first;
		++count;
	}
	return count;
}

class Connection {

	int id;

public :

	 Connection(string &hostname): id(open_connection(hostname.c_str() )) {}
	 Connection(const Connection &other){

	 }
	 Connection &operator=(const Connection &other) const {
		 return *this;
	 }

	 int open_connection(const char *component) {

	 }
	 void send(int connection_id, const char *msg){
		 if (id == connection_id)
		 send_message(msg);
	 }

	 void send_message( const string &msg) const{
		 send(id, msg.c_str());
	 }

	 int close_connection(int connection_id){

	 }

	 ~Connection(){
		 close_connection(id);
	 }

};


*/

class GameObject {
   protected:
       string obj_name;
       double x_pos;
       double y_pos;
   public:
       GameObject(): obj_name(""), x_pos(0.0), y_pos(0.0){}
       GameObject(const string &n, double x, double y) :
           obj_name(n), x_pos(x), y_pos(y) {}
       const string name() const { return obj_name; }
       double x() const { return x_pos; }
       double y() const { return y_pos; }
       virtual void moveto(double x, double y) {
           x_pos = x; y_pos = y;
       }
};


// the const in the name method is means the methods cannot be manipulated, all its members cannot be changed
//this is the same for all the other cost methods, those methods and their members or fields cannot be changed.

// the virtual moveto function is a function that can be redefined and overrideen by any derived classes of GameObject class


class DecayingObject : public GameObject{

	double dist;
public :
	 DecayingObject(const string &n,
	                       double x, double y) :
	            GameObject(n, x, y), dist(0) {}
	DecayingObject(const DecayingObject & other) {}
	DecayingObject &operator=(const DecayingObject & other) const{

		return *this;
	}

	virtual void moveto(double x, double y) {
	     dist += sqrt((pos_x-x)*(pos_x-x) +
	              (pos_y-y)*(pos_y-y));
	      GameObject::moveto(x, y);
	  }
	double distance_travelled() const { return dist; }

};


// i === f1 if legal because the h is a DecayingObject object which is a subtype of Gmaeobject, therefore v in the parameters is copying the h object
// i === f2 is legal because DecayingObject is a subtype of Gameobject, meaning it inherits from Gamebject, the reference v in the parameters mean that v is an alias h object
// i === f3 is illegal because GameObject h is not a sub type of DecayingObject object, we are expecting a DecayingObject in the paramenters so g cannot be presummed as a DecayingObject and DecayingObject v is not a base class where g inherit from
// i === f4 is legal becuase we are expecting a Gmaobject pointer in the paramenters, DecayingObject h is a subtype of Gmaobject which make it legal, and also becuase we are passing by reference, we are passing in the memory address of the h


int main() {

	return 0;
}
