//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

using namespace std;
using namespace programmingparticles;

int main(int argc, char** argv) {

	srand(time(NULL)); //srand() seeds the random number generator with a number, which makes it produce a different sequence numbers every time


	// Initialise screen
	Screen screen;
	if (screen.init() == false) {
		cout << "ERROR INITIALIZING SCREEN WITH SDL." << endl;
	}
	//cout << "SDL Init succeeded." << endl;

	Swarm swarm;

	float redTime = 0.0006;
	float greenTime = 0.00007;
	float blueTime = 0.00002;

	while (true) {


		// Animate colors
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char red = (unsigned char )((1 + sin(elapsed * redTime)) * 128);
		unsigned char green = (unsigned char )((1 + sin(elapsed * greenTime)) * 128);
		unsigned char blue = (unsigned char )((1 + cos(elapsed * blueTime)) * 128);


		// All Particle objects
		const Particle * const pParticles = swarm.getParticles();


		// Update particles
		for(int i=0; i < Swarm::NUMBER_OF_PARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			//int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;
			int y = particle.m_y * (Screen::SCREEN_WIDTH/2) + (Screen::SCREEN_HEIGHT/2);

			screen.setPixel(x, y, red, green, blue);
		}

		//clear the screen and redraw the screen to make illusion of movement
		/*
		// Fill Screen
		for(int y=0; y < Screen::SCREEN_HEIGHT; y++){
			for(int x=0; x < Screen::SCREEN_WIDTH; x++){

				screen.setPixel(x, y, red, green, blue);
			}
		}

		// this is the pixel in the center of the screen
		//screen.setPixel(400, 300, 0, 0, 0);
		 */

		// Blur screen
		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if(screen.proccessEvents() == false){
			break;
		}
	}

	screen.close();

	return 0;
}
