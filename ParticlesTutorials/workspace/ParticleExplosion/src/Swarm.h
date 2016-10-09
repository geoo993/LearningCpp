/*
 * Swarm.h
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace programmingparticles {

class Swarm {

public:
	const static int NUMBER_OF_PARTICLES = 5000;

private:

	Particle *m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() { return m_pParticles; };
	void update(int time);
};

}

#endif /* SWARM_H_ */
