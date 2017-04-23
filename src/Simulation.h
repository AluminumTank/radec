#ifndef SIMULATION
#define SIMULATION

#include "wire.h"
#include "event.h"
#include "gate.h"
#include "andGate.h"
#include "nandGate.h"
#include "orGate.h"
#include "norGate.h"
#include "xnorGate.h"
#include "xorGate.h"
#include "notGate.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Simulation {
	public:
		bool parseCircuit(string fileName);
		void simulate();
		void print();
	private:
		Wire* findWire(int n);
		int getDelay(string d);

		priority_queue<Event> e;
		vector<Gate*> gates;
		vector<Wire*> wires;
};

#endif // !SIMULATION
