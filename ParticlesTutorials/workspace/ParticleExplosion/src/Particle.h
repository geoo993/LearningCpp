/*
 * Particle.h
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <SDL.h>
#include <math.h>

namespace programmingparticles {

struct Particle { // class and struct are the same thing, the onl difference is that by default class members of struct are public
//class Particle { //when setting class, its members by default are private


	//member variable
	double m_x;
	double m_y;

	double m_movementSpeed;
	double curlValue;

private:
	double m_speed;
	double m_direction;

	//double m_xSpeed ;
	//double m_ySpeed ;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);


};

}

#endif /* PARTICLE_H_ */
