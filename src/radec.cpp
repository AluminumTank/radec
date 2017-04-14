#include <iostream>
#include <fstream>
#include <queue>
#include "wire.h"
#include "orGate.h"
#include "xorGate.h"
#include "norGate.h"
#include "xnorGate.h"
#include "andGate.h"
#include "nandGate.h"
#include "notGate.h"
#include "event.h"

using namespace std;

int getDelay(string d);
bool parseCircuit(priority_queue<event> e, vector<gate*> &gates,
		vector<wire*> &wires, string fileName);
wire* findWire(int n, vector<wire*> wires);
bool parseVector(priority_queue<event> e, string fileName);

int main() {
	// 1. Parse circuit file to create in-memory data structure of Gates and Wires
	//		to simulate
	vector<gate*> gates;
	vector<wire*> wires;
	priority_queue<event> e;
	string fileName;
	getline(cin, fileName);
	bool parseSuccess = parseCircuit(e, gates, wires, fileName);

	if(parseSuccess) {
		// 2. Parse the vector file to initialize the simulation Queue with initial
		//		Wire state (i.e., value) changes
		parseSuccess = parseVector(e, fileName);

	// 3. Simulate the circuit using Event-driven control
	// first, remove the top Event e in the Queue
	// second, determine if e causes a future Wire state change
	// third, create and queue any future Wire state changes as new Events
	// fourth, apply e's effects

	// 4. Print the results of the simulation
	}
}

bool parseCircuit(priority_queue<event> e, vector<gate*> &gates,
		vector<wire*> &wires, string fileName) {
	ifstream in;
	in.open(fileName + ".txt");
	if(in.fail()) {
		cerr << endl << fileName << ".txt could not be opened :(";
		exit(1);
	}

	string tmpString, tmpType;
	int tmp1, tmp2, tmp3;
	wire *tmpWire;
	gate *tmpGate;
	getline(in, tmpString);

	while(!in.eof()) {
		in >> tmpType;

		in >> tmpString;
		in >> tmp1;
		if(tmpType == "INPUT") {
			tmpWire = new wire(tmp1, true, tmpString);
			wires.push_back(tmpWire);
		}else if(tmpType == "OUTPUT") {
			tmpWire = new wire(tmp1, false, tmpString);
			wires.push_back(tmpWire);
		}else if(tmpType == "NOT") {
			in >> tmp2;
			tmpGate = new notGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "AND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new andGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "NAND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new nandGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "OR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new orGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "XOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new xorGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "NOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new norGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}else if(tmpType == "XNOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new xnorGate(&e, getDelay(tmpString), findWire(tmp1, wires),
					findWire(tmp2, wires), findWire(tmp3, wires));
			gates.push_back(tmpGate);
		}
	}
}

wire* findWire(int n, vector<wire*> wires) {
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		if(n == (**i).getNumber()) return *i;
	}
	return nullptr;
}

int getDelay(string d) {
	d.resize(d.size() - 2);
	return atoi(d.c_str());
}

bool parseVector(priority_queue<event> e, string fileName) {
	//TODO
}
