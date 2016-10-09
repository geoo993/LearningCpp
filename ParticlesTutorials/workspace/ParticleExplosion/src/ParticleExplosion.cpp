//============================================================================
// Name        : ParticleExplosion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include "Screen.h"

using namespace std;
using namespace programmingparticles;

int main(int argc, char** argv) {

//	//bit shifting
//	// 0xFF123456
//	unsigned char alpha = 0xFF;
//	unsigned char red = 0x12;
//	unsigned char green = 0x34;
//	unsigned char blue = 0x56;
//
//	unsigned int color = 0;
//
//	color += alpha;
//
//	//color = color << 8; same as color <<= 8; the bit shift << in cpp is very useful, where you would often want to shift bits and bites around, this is a great low level programming example.
//	//color = color << 24;
//	color <<= 8;
//	color += red;
//	color <<= 8;
//	color += green;
//	color <<= 8;
//	color += blue;
//
//	//cout << color << endl;
//	//cout << hex << color << endl;
//	cout << setfill('0') << setw(8) << hex << color << endl;
//
//
//	color >>= 8; //there is also a right bit operator >>
//	color -= alpha;
//
//	cout << setfill('0') << setw(8) << hex << color << endl;



	Screen screen;
	if (screen.init() == false) {
		cout << "ERROR INITIALIZING SCREEN WITH SDL." << endl;
	}

	while (true) {

		if(screen.proccessEvents() == false){
			break;
		}
	}

	screen.close();

	return 0;
}
