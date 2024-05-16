#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int quantity = 0, number = 1;

Example::Example(int data) {
	// (3)
	Data = data;
	quantity++;
	Quantity = quantity;
	Number = number;
	number++;
	cout << "Example #" << Number 
	<< " is created" << endl;
}

void Example::getData() {
	// (4)
	cout << "The data of Example #" <<
	Number << " is " << Data << endl;
}

Example::~Example() {
	// (5)
	cout << "Example #" << Number 
	<< " is destroyed" << endl;
}