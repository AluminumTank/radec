#include "Simulation.h"

using namespace std;

int main() {
	// 1. Parse circuit file to create in-memory data structure of Gates and Wires
	//		to simulate
	string fileName;
	Simulation e;

	cout << "Please enter filename:\n";
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
	e.simulate();

	// 4. Print the results of the simulation
	e.print();
}
