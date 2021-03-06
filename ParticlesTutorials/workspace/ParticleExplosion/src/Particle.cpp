/*
 * Particle.cpp
 *
 *  Created on: Oct 9, 2016
 *      Author: GeorgeQuentin
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Particle.h"
#include <math.h>

using namespace std;

namespace programmingparticles {

Particle::Particle() :
	m_x(0), m_y(0) {
	//Particle::Particle() {
	// TODO Auto-generated constructor stub
	//cout << "PARTICLE CONSTRUCTOR " << endl;

	init();

}

void Particle::init() {

	m_x = 0;
	m_y = 0;

	//(double)rand()/RAND_MAX;// this is a number ranging from 0 to 1
	//(2.0 * rand())/RAND_MAX;// this is a number ranging from 0 to 2
	//m_x = ((2.0 * rand()) / RAND_MAX) - 1;// x is going from -1 to 1
	//m_y = ((2.0 * rand()) / RAND_MAX) - 1;// y is going from -1 to 1

	m_movementSpeed = 0.05;
	curlValue = 0.0004;

	m_direction = (2 * M_PI * rand()) / RAND_MAX;// choosing an angle
	m_speed = (m_movementSpeed * rand()) / RAND_MAX;

	//m_speed = m_speed*m_speed;
	m_speed *= m_speed;

	//( ( (2.0 * rand()) /RAND_MAX ) - 1) gives a value between -1 and 1
	//m_xSpeed = m_movementSpeed * (((2.0 * rand()) / RAND_MAX) - 1);
	//m_ySpeed = m_movementSpeed * (((2.0 * rand()) / RAND_MAX) - 1);
	//m_ySpeed = m_movementSpeed ;

}

void Particle::update(int interval) {

	//make particles curl
	m_direction += interval * curlValue;

	//moving in a particular direction
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	// interval is like time.delatime in unity
	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if (m_x < -1.0 || m_x >= 1.0 || m_y < -1.0 || m_y >= 1.0) {
		init();
	}

	if (rand() < (RAND_MAX/200)){
		init();
	}


	//random motion movement
	//snow movement
	//float movement
	//bounce container movement

	//m_x += m_xSpeed;
	//m_y += m_ySpeed;

	//	if (m_y > 1.0 + 0.1) {
	//
	//		m_y = -1.0 ;
	//
	//		m_xSpeed = m_movementSpeed * (((2.0 * rand()) / RAND_MAX) - 1);
	//		m_ySpeed = m_movementSpeed ;
	//	}

	//	if (m_x < -1.0 || m_x >= 1.0) {
	//		m_xSpeed = -m_xSpeed;
	//	}
	//
	//	if (m_y < -1.0 || m_y >= 1.0) {
	//		m_ySpeed = -m_ySpeed;
	//	}

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
	//cout << "PARTICLE DESTRUCTOR " << endl;
}

}
