#include "wire.h"
#include "pQueue.h"
#include "orGate.h"
#include "andGate.h"
#include "notGate.h"

int main() {
	// 1. Parse circuit file to create in-memory data structure of Gates and Wires
	//		to simulate
	vector<gate*> gates;
	vector<wire*> wires;
	string fileName;
	getline(cin, fileName);
	bool parseSuccess = parseCircuit(gates, wires, fileName);

	if(parseSuccess) {
		// 2. Parse the vector file to initialize the simulation Queue with initial
		//		Wire state (i.e., value) changes
		queue e;
		parseSuccess = e.parseVector(fileName);

	// 3. Simulate the circuit using Event-driven control
	// first, remove the top Event e in the Queue
	// second, determine if e causes a future Wire state change
	// third, create and queue any future Wire state changes as new Events
	// fourth, apply e's effects

	// 4. Print the results of the simulation
}

bool parseCircuit(gates, wires) {
	//TODO
}
