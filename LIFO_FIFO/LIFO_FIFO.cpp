// LIFO_FIFO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LIFO.h"
#include "FIFO.h"

#include "Menu.h"

using namespace std;

struct non_primitive {
	int info;
	double squared;
	
	non_primitive() {

	}

	non_primitive(int info, double squared) {
		this->info = info;
		this->squared = squared;
	}
};


void LIFO_test_primitive() {
	LIFO<int> * stack = new LIFO<int>(5); // list with 5 entries

	// push max data
	for (int i = 0; i < 5; i++) {
		stack->push(i);
	}

	// provoke push failure by pushing outside bounds
	stack->push(0);

	// provoke failure by changing size from 5 to 4
	stack->setMaxSize(4);

	// attempt to increase size by 1
	stack->setMaxSize(6);

	// push 1 more data to check if it worked
	stack->push(5);

	// pop all data and print while

	for (int i = 0; i < 6; i++) {
		cout << stack->pop() << endl;
	}

	// provoke pop error
	stack->pop();

	// try to make size 1
	stack->setMaxSize(1);

	// push 1 data
	stack->push(0);

	// provoke error with push
	stack->push(1);

	// clear stack
	stack->pop();

	// increase size, then push data
	stack->setMaxSize(10);

	for (int i = 0; i < 10; i++) {
		stack->push(i);
	}

	// finally print data
	stack->printData();

	// empty whole stack
	cout << endl << "EMPTYING...\n";

	for (int i = 0; i < 10; i++) {
		cout << stack->pop() << endl;
	}

	cout << "\n\nNow that it's empty, try and get data, expect none";
	cout << endl;
	stack->printData();
}

void LIFO_example_non_primitive() {
	/*
	All tests were passed in pritimive example;
	Checking functionallity of callback in this section;
	*/

	LIFO<non_primitive> * stack = new LIFO<non_primitive>(
		[](non_primitive entry) { // define callback for cout
		cout << "Number: " << entry.info << "  Power of 2: " << entry.squared;
	}, 10);

	for (int i = 0; i < 10; i++) {
		stack->push(non_primitive(
			i, pow(i, 2)
		));
	}

	stack->printData();

	// empty stack

	cout << "Pop trace:\n\n";
	for (int i = 0; i < 10; i++) {
		non_primitive entry = stack->pop();
		cout << "Number: " << entry.info << "  Power of 2: " << entry.squared;
		cout << endl;
	}

	// Test done
}

void FIFO_test_primitive() {
	FIFO<int> * stack = new FIFO<int>(5); // list with 5 entries

										  // push max data
	for (int i = 0; i < 5; i++) {
		stack->push(i);
	}

	stack->printData();
	// provoke push failure by pushing outside bounds
	stack->push(0);

	// provoke failure by changing size from 5 to 4
	stack->setMaxSize(4);

	// attempt to increase size by 1
	stack->setMaxSize(6);

	// push 1 more data to check if it worked
	stack->push(5);

	// pop all data and print while

	for (int i = 0; i < 6; i++) {
		cout << stack->pop() << endl;
	}

	// provoke pop error
	stack->pop();

	// try to make size 1
	stack->setMaxSize(1);

	// push 1 data
	stack->push(0);

	// provoke error with push
	stack->push(1);

	// clear stack
	stack->pop();

	// increase size, then push data
	stack->setMaxSize(10);

	for (int i = 0; i < 10; i++) {
		stack->push(i);
	}

	// finally print data
	stack->printData();

	// empty whole stack
	cout << endl << "EMPTYING...\n";

	for (int i = 0; i < 10; i++) {
		cout << stack->pop() << endl;
	}

	cout << "\n\nNow that it's empty, try and get data, expect none";
	cout << endl;
	stack->printData();

	system("CLS");

	for (int i = 0; i < 5; i++) {
		stack->push(i);
	}

	stack->printData();
	// provoke push failure by pushing outside bounds
	stack->push(0);

	// provoke failure by changing size from 5 to 4
	stack->setMaxSize(4);

	// attempt to increase size by 1
	stack->setMaxSize(6);

	stack->printData();
	// push 1 more data to check if it worked
	stack->push(5);

	stack->printData();
	// pop all data and print while

	for (int i = 0; i < 6; i++) {
		cout << stack->pop() << endl;
	}

	// provoke pop error
	stack->pop();

	// try to make size 1
	stack->setMaxSize(1);

	// push 1 data
	stack->push(0);

	// provoke error with push
	stack->push(1);

	// clear stack
	stack->pop();

	// increase size, then push data
	stack->setMaxSize(10);

	for (int i = 0; i < 10; i++) {
		stack->push(i);
	}

	// finally print data
	stack->printData();

	// empty whole stack
	cout << endl << "EMPTYING...\n";

	for (int i = 0; i < 10; i++) {
		cout << stack->pop() << endl;
	}

	cout << "\n\nNow that it's empty, try and get data, expect none";
	cout << endl;
	stack->printData();
}

void FIFO_example_non_primitive() {
	/*
	All tests were passed in pritimive example;
	Checking functionallity of callback in this section;
	*/

	FIFO<non_primitive> * stack = new FIFO<non_primitive>(
		[](non_primitive entry) { // define callback for cout
		cout << "Number: " << entry.info << "  Power of 2: " << entry.squared;
	}, 10);

	for (int i = 0; i < 10; i++) {
		stack->push(non_primitive(
			i, pow(i, 2)
		));
	}

	stack->printData();

	// empty stack

	cout << "Pop trace:\n\n";
	for (int i = 0; i < 10; i++) {
		non_primitive entry = stack->pop();
		cout << "Number: " << entry.info << "  Power of 2: " << entry.squared;
		cout << endl;
	}


	// Test done
}

int main()
{
	/*cout << endl << "FIFO test: " << endl;
	FIFO_example_non_primitive();

	cout << endl << "LIFO test:" << endl;
	LIFO_example_non_primitive();*/

	Menu<string> * menu = new Menu<string>();

	menu->start();

	system("pause");

    return 0;
}

