#include <fstream>
#include "wire.h"
#include "pQueue.h"
#include "orGate.h"
#include "andGate.h"
#include "notGate.h"

using namespace std;

int getDelay(string d);
bool parseCircuit(vector<gate*> &gates, vector<wire*> &wires, fileName);
wire* findWire(int n, vector<wire*> wires);

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
		priority_queue< e;
		parseSuccess = e.parseVector(fileName);

	// 3. Simulate the circuit using Event-driven control
	// first, remove the top Event e in the Queue
	// second, determine if e causes a future Wire state change
	// third, create and queue any future Wire state changes as new Events
	// fourth, apply e's effects

	// 4. Print the results of the simulation
}

bool parseCircuit(vector<gate*> &gates, vector<wire*> &wires, fileName) {
	ifstream in;
	circuit.open(fileName + ".txt");
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
		tmpType << in;

		tmpString << in;
		tmp1 << in;
		if(tmpType == "INPUT") {
			tmpWire = new wire(tmp1, true, tmpString);
			wires.push_back(tmpWire);
		}else if(tmpType == "OUTPUT") {
			tmpWire = new wire(tmp1, false, tmpString);
			wires.push_back(tmpWire);
		}else if(tmpType == "NOT") {
			tmp2 << in;
			tmpGate = new notGate(getDelay(tmpString), findWire(tmp1),
					findWire(tmp2));
			gates.push_back(tmpGate);
		}else if(tmpType == "AND") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new andGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
					findWire(tmp3));
			gates.push_back(tmpGate);
		}else if(tmpType == "NAND") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new nandGate(getDelay(tmpString), findWire(tmp1),
					findWire(tmp2), findWire(tmp3));
			gates.push_back(tmpGate);
		}else if(tmpType == "OR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new orGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
					findWire(tmp3));
			gates.push_back(tmpGate);
		}else if(tmpType == "XOR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new xorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
					findWire(tmp3));
			gates.push_back(tmpGate);
		}else if(tmpType == "NOR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new norGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
					findWire(tmp3));
			gates.push_back(tmpGate);
		}else if(tmpType == "XNOR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new xnorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
					findWire(tmp3));
			gates.push_back(tmpGate);
		}
	}
}

wire* findWire(int n, vector<wire*> wires) {
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		if(n == *i) return i;
	}
	return nullptr;
}

int getDelay(string d) {
	d.resize(d.size() - 2);
	return atoi(d.c_str());
}
