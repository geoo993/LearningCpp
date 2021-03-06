//============================================================================
// Name        : MultipleInheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class MusicalInstrument {

public:

	//virtual means they could be overriden
	virtual void play(){ cout << "Playing instrument ... " << endl; }
	virtual void reset(){ cout << "Resetting instrument ..." << endl; }
	virtual ~MusicalInstrument(){};
};

class Machine{

public:
	virtual void start(){ cout << "Starting machine ... " << endl; }
	virtual void reset(){ cout << "Resetting machine ..." << endl; }

	virtual ~Machine(){};

};

struct Synthesizer: public MusicalInstrument , public Machine{

	virtual ~Synthesizer(){};
};

int main() {

	//in general its better to avoid multiple inheritance because of the ambiguity of the methods

	Synthesizer *pSynth = new Synthesizer();
	pSynth->play();
	pSynth->start();

	//pSynth->reset();//will not work, this is ambiguous
	pSynth->MusicalInstrument::reset();
	pSynth->Machine::reset();

	delete pSynth;

	return 0;
}
