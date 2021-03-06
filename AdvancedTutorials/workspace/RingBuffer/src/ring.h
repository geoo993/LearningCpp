/*
 * ring.h
 *
 *  Created on: 5 Nov 2016
 *      Author: GeorgeQuentin
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
#include <cstdlib>
#include <initializer_list>


using namespace std;


template<typename T>
class ring {
private:

	unsigned int m_pos;//position in the array
	unsigned int m_size; //size of the array (elements)
	unsigned int m_realsize; // actual size of allocated memory
	const static int dyn_array_step = 128; // initial size of array memory (elements)
	const static int dyn_array_mult = 2; // multiplier (enlarge array memory
	// dyn_array_mult times  )
	T *m_values;

public:

	class iterator;

public:

	enum exception { MEMFAIL }; // exception enum

	ring()//constructor
	{
		m_pos = 0;
		m_realsize = dyn_array_step; // First, allocate step
		// for dyn_array_step items
		m_size = 0;
		m_values = (T *) malloc(m_realsize * sizeof(T));

		if (m_values == NULL)
			throw MEMFAIL;

		cout << " Constructor" << endl;
	}
	~ring() {

		//		if (m_values) {
		//			free( m_values); // Freeing memory
		//			m_values = NULL;
		//		}

		delete[] m_values;
	}

	ring(const ring &other) //: m_pos(other.m_pos), m_size(other.m_size), m_realsize(other.m_realsize), m_values(other.m_values) // copy constructor
	{
		m_values = (T *) malloc(sizeof(T) * other.m_realsize);
		if (m_values == NULL)
			throw MEMFAIL;

		memcpy(m_values, other.m_values, sizeof(T) * other.m_realsize);
		// memcpy call -- coping memory contents
		m_realsize = other.m_realsize;
		m_size = other.m_size;
		m_pos = other.m_pos;

		cout << "Copy Constructor" << endl;
	}

	ring(unsigned int m_size) :
		m_pos(0), m_size(m_size), m_realsize(dyn_array_step), m_values(NULL) {

		m_values = new T[m_size];
	}

	ring(initializer_list<T> values)//constructor
	{
		//m_pos = 0;
		//m_realsize = dyn_array_step; // First, allocate step
				// for dyn_array_step items
		//m_size = 0;
		//m_values = values;

		for(auto value: values){

			m_values[m_pos] = value;
			m_pos ++;
			m_size ++;
			//cout << value << endl;
		}

		if (m_values == NULL)
			throw MEMFAIL;

		cout << " Constructor with Initialiser List" << endl;
	}

	//containers
public:

	void * pGet()
	{
	    return m_values; // return void* pointer
	}

	unsigned int size() const {//get the size of the array
		return m_size;
	}


	void clear() {// clear array memory

		m_size = 0;
		m_values = (T *)realloc(m_values, sizeof(T)*dyn_array_step);
					  // set initial memory size again
		m_realsize = dyn_array_step;
	}

	void swap(T& a, T& b) // clear x reallocating
	{
		T c(std::move(a));
		a = std::move(b);
		b = std::move(c);
	}

	T &get(unsigned int index) {// get element in array with get
		return m_values[index];
	}

	void setSize(unsigned int newsize) // set size of array (elements)
	{
		m_size = newsize;

		if (m_size != 0)
		{
			// change array memory size
			// if new size is larger than current
			// or new size is less then half of the current
			if ((m_size > m_realsize) || (m_size < m_realsize/2))
			{
		    	m_realsize = m_size;
		    	m_values = (T *)realloc(m_values, sizeof(T)*m_size);

				if (m_values == NULL)
					throw MEMFAIL;
			}
		}
		else
			clear();
	}

	//sequences
public:

	//	 T & operator[](int index) const
	//	 T & operator[](int index) const; // & the Bad

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

	void add(const T & value) {

		//m_values[m_pos] = value;
		//m_pos++;

		m_values[m_pos++] = value;
		if (m_pos == m_size) {

			m_pos = 0;
		}


//		m_size++;
//
//	    if (m_size > m_realsize)
//	    {
//			m_realsize *= dyn_array_mult;
//
//			m_values = (T *)realloc(m_values, sizeof(T) * m_realsize);
//
//			if (m_values == NULL)
//				throw MEMFAIL;
//	    }
//
//	    m_values[m_size-1] = value;


	}


//	void pop() {
//
//		if (m_size > 0) {
//			delete &m_values[0];
//		}
//	}

	void erase(unsigned int pos) { //delete array item
//		if (m_size >= pos) {
//			delete m_values[pos];
//		}

		if (m_size == 1) // If array has only one element
			clear(); // than we clear it, since it will be deleted
		else
		{
			// otherwise, shift array elements
			for(unsigned int i=pos; i<m_size-1; i++)
				m_values[i] = m_values[i+1];

			// decrease array size
			m_size--;
		}
	}




	//operators
public :
	const ring &operator=(const ring &other) // assignment operator
	{
	    if (this == &other) // in case somebody tries assign array to itself
			return *this;

		if (other.m_size == 0) // is other array is empty -- clear this array
			clear();

		setSize(other.m_size); // set size

	    memcpy(m_values, other.m_values, sizeof(T)*other.m_size);

	    cout << "Assignment running" << endl;

	    return *this;
	}

	T &operator [](unsigned int index) // get array item
	{
	    return m_values[index]; // return array element
	}

	//iterator
public :
	iterator begin(){
		return iterator(0, *this);
	}
	iterator end(){
		return iterator(m_size, *this);
	}

};


template<typename T>
class ring<T>::iterator {

private:
	unsigned int pos;
	ring &m_ring;

public:
	iterator(unsigned int pos, ring &r): pos(pos), m_ring(r){

	}

	iterator &operator++() //prefix operator implementation
	{
		pos++;
		return *this;
	}
	iterator &operator++(int)//postfix operator implementation
	{
		pos++;
		return *this;
	}

	bool operator!=(const iterator &other) const//not equal operator implementation
	{
		return (pos != other.pos);
	}

	bool operator==(const iterator &other) const//equals operator implementation
	{
		return pos == other.pos;
	}

	T &operator*(){
		return m_ring.get(pos);
	}



};

#endif /* RING_H_ */
