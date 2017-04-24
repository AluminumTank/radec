#ifndef SIMULATION
#define SIMULATION

#include "Wire.h"
#include "Event.h"
#include "Gate.h"
#include "AndGate.h"
#include "NandGate.h"
#include "OrGate.h"
#include "NorGate.h"
#include "XnorGate.h"
#include "XorGate.h"
#include "NotGate.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Simulation {
	public:
		bool parseCircuit(string fileName);
		bool parseVector(string fileName);
		void simulate();
		void print();
	private:
		Wire* findWire(int n);
		int getDelay(string d);

		priority_queue<Event> e;
		vector<Gate*> gates;
		vector<Wire*> wires;
		int eventNum;
};

#endif // !SIMULATION
