#include "Simulation.h"

using namespace std;

int main() {
	// 1. Parse circuit file to create in-memory data structure of Gates and Wires
	//		to simulate
	string fileName;
	Simulation e;
	int len = 60;

	cout << "Please enter filename: ";
	getline(cin, fileName);
	
	e.parseCircuit(fileName);

	// 2. Parse the vector file to initialize the simulation Queue with initial
	//		Wire state (i.e., value) changes
	e.parseVector(fileName);

	// 3. Simulate the circuit using Event-driven control
	// first, remove the top Event e in the Queue
	// second, determine if e causes a future Wire state change
	// third, create and queue any future Wire state changes as new Events
	// fourth, apply e's effects
	e.simulate(len);

	// 4. Ask how long you want the line length to be
	//	Print the results of the simulation
	cout << "How long do you want to simulate to (default 60)? ";
	if (cin.peek() == '\n') {
		len = 60;
	}
	else if (!(cin >> len)) {
		cout << "Invalid input using 60.\n";
	}
	e.print(len);
	system("pause");
}
