/*
 * ring.h
 *
 *  Created on: 5 Nov 2016
 *      Author: GeorgeQuentin
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<typename T>
class ring {
private:
	int initial_size;
public:

	class iterator;

	ring();
	ring(int initial_size) :
		initial_size(initial_size) {

	}
	/*int size() const;
	 void clear();
	 T & operator[](int index) const
	 T & operator[](int index) const; // & the Bad
	 T & front() {
	 return operator[](0);
	 }
	 const T & front() const {
	 return operator[](0);
	 }
	 T & back() {
	 return operator[](size() - 1);
	 }
	 const T & back() const {
	 return operator[](size() - 1);
	 }
	 void add(const T & x);
	 void pop();*/

	virtual ~ring();

};
template<typename T>
class ring<T>::iterator {
public:
	void print(){
		cout << "Hello from Ring iterator... Type Id: " << typeid(T).name() << endl;
	}

};


#endif /* RING_H_ */
