//============================================================================
// Name        : StacksAndQueues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
private:
	int id;
	string name;

public:

	Test() :
		id(0), name("") {
	}

	Test(int id, string name) :
		id(id), name(name) {
	}

	~Test() {
		//cout << "Destroyed Object" << endl;
	}

	void print() const {
		cout << name << ": " << id << endl;
	}

	bool operator<(const Test &other) const {
		return name < other.name;
	}
};

int main() {

	//STACK: LAST IN FIRST OUT
	//you can use what ever you like in a stack, just like the other containers
	//a stack in a last in, first out structure, it is called a stack meaning a pile of objects
	//a stack is like a pile of object, i.e a stack of plates for example, you can add to it at the top and do the same when you want to remove
	//so the previous element added in the stack is going to be the one to be removed first
	stack<Test> testStack;

	//you add items by pushing them in the stack
	testStack.push(Test(15, "Lola"));
	testStack.push(Test(23, "Sue"));
	testStack.push(Test(28, "John"));

	//there is no way of iterating through a stack, if you think you need to iterate through it then do not use it
	//the top value in the stack is the oject that ws recently added
	Test &test1 = testStack.top();
	test1.print();

	//you can pop values off the stack to remove the current value that at the top of the stack
	testStack.pop();

	Test &test2 = testStack.top();
	test2.print();

	cout << endl;
	while (testStack.size() > 0) {
		Test &test = testStack.top();
		test.print();
		testStack.pop();
	}

	cout << endl;


	//QUEUE: FIRST IN FIRST OUT
	// a queue unlike a stack, is first in first out, whereby you are using going at the beginning of the stack to add elements to it
	queue<Test> testQueue;

	//you add items by pushing them in the queue, same like a stack
	testQueue.push(Test(15, "Ela"));
	testQueue.push(Test(23, "Yousuf"));
	testQueue.push(Test(28, "Daniel"));
	testQueue.push(Test(58, "Simba"));
	testQueue.push(Test(13, "Zelda"));

	//you can pop items from the queue, which is going to remove items from the front of the queue meaning the first element that was added and not the recent element that was added
	testQueue.pop();

	testQueue.front().print();

	testQueue.back().print();

	cout << endl;

	while (testQueue.size() > 0) {
		Test &test = testQueue.front();
		test.print();
		testQueue.pop();
	}

	return 0;
}
