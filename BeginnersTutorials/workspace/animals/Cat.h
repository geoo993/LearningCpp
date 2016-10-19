/*
 * Cat.h
 *
 *  Created on: Oct 16, 2016
 *      Author: GeorgeQuentin
 */

#ifndef CAT_H_
#define CAT_H_

namespace catnamespace {

void saySomething();

	class Cat {
	public:
		Cat();
		void speak();
		virtual ~Cat();
	};

}
#endif /* CAT_H_ */
