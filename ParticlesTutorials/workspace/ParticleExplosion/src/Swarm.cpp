/*
 * Swarm.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#include "Swarm.h"

namespace programmingparticles {

Swarm::Swarm(): lastTime(0) {
	// TODO Auto-generated constructor stub
	//cout << "SWARM CONSTRUCTOR " << endl;
	m_pParticles = new Particle[NUMBER_OF_PARTICLES];
}

void Swarm::update(int time) {

	int interval = time - lastTime;

	for (int i = 0; i < Swarm::NUMBER_OF_PARTICLES; i++) {
		m_pParticles[i].update(interval);
	}

	lastTime = time;
}

Swarm::~Swarm() {
	// TODO Auto-generated destructor stub
	//cout << "SWARM DESTRUCTOR " << endl;

	delete[] m_pParticles;
}

}
