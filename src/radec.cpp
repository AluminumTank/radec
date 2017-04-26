// Name: radec.cpp
// Author: Joel Beckmeyer, Daniel Parker
// Date: 2017-04-26
// Purpose: to use the library we have developed in order to simulate a boolean
//	logic circuit

#include "Simulation.h"

using namespace std;

int main() {
	// 1. Parse circuit file to create in-memory data structure of Gates and Wires
	//		to simulate
	string fileName;
	Simulation e;
	int len = 60;
	bool canOpen;

	cout << "Please enter filename: ";
	getline(cin, fileName);
	
	canOpen = e.parseCircuit(fileName);

	// 2. Parse the vector file to initialize the simulation Queue with initial
	//		Wire state (i.e., value) changes
	canOpen = e.parseVector(fileName);

	// 3. Simulate the circuit using Event-driven control
	// first, remove the top Event e in the Queue
	// second, determine if e causes a future Wire state change
	// third, create and queue any future Wire state changes as new Events
	// fourth, apply e's effects
	if(canOpen) {
		cout << "What time do you want to simulate to (default 60ns)? ";
		if (cin.peek() == '\n') {
			len = 60;
		}
		else if (!(cin >> len)) {
			cout << "Invalid input; using 60.\n";
			len = 60;
		}
		e.simulate(len);

		// 4. Print the results of the simulation
		e.print(len);
		system("pause");
	}
	return 0;
}
