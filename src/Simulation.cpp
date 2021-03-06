#include "Simulation.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// parse the Circuit file and create in memory data structure
bool Simulation::parseCircuit(string fileName)
{
	ifstream in;
	in.open(fileName + ".txt");
	if (in.fail()) {
		cerr << endl << fileName << ".txt could not be opened :(";
		return false;
	}

	string tmpString, tmpType;
	int tmp1, tmp2, tmp3;
	Wire *tmpWire;
	Gate *tmpGate;

	// get rid of first line
	getline(in, tmpString);

	while (true) {
		if (!(in >> tmpType)) break;
		if (!(in >> tmpString)) break;
		if (!(in >> tmp1)) break;

		// create an in-memory wire
		if (tmpType == "INPUT" || tmpType == "OUTPUT") {
			tmpWire = findWire(tmp1);
			tmpWire->convertToIO(tmpString);
		}
		// rest of blocks deal with gates and have nearly identical structures
		else if (tmpType == "NOT") {
			in >> tmp2;
			tmpGate = new NotGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2));

			// push gate onto Simulation gates vector
			gates.push_back(tmpGate);
			// also push gate onto input wire's gate vector
			findWire(tmp1)->addGate(tmpGate);
		}
		else if (tmpType == "AND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new AndGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
		else if (tmpType == "NAND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new NandGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2), findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
		else if (tmpType == "OR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new OrGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
		else if (tmpType == "XOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new XorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
		else if (tmpType == "NOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new NorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
		else if (tmpType == "XNOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new XnorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));

			gates.push_back(tmpGate);
			findWire(tmp1)->addGate(tmpGate);
			findWire(tmp2)->addGate(tmpGate);
		}
	}
	return true;
}

// parse the Vector file and add provided events to the priority_queue
bool Simulation::parseVector(string fileName) {
	ifstream in;
	in.open(fileName + "_v.txt");
	if (in.fail()) {
		cerr << endl << fileName << "_v.txt could not be opened :(\n";
		return false;
	}

	string tmpString, valInt;
	int timeInt;
	Wire *tmpWire = nullptr;

	// get rid of first line
	getline(in, tmpString);

	// pull in all data from Vector file
	while(true) {
		if (!(in >> tmpString)) break;
		if (!(in >> tmpString)) break;
		if (!(in >> timeInt)) break;
		if (!(in >> valInt)) break;

		// find wire with provided name
		for(auto i = wires.begin(); i != wires.end(); ++i) {
			if((**i).getName() == tmpString) {
				tmpWire = *i;
			}
		}

		if (valInt == "X") {
			e.push(Event(-1, timeInt, tmpWire));
		}
		else {
			e.push(Event(atoi(valInt.c_str()), timeInt, tmpWire));
		}
	}
}

// simulate the circuit using the provided in-memory circuit and queue of events
void Simulation::simulate(int simTime) {
	// loop through event queue
	while(!e.empty()) {
		bool changed;
		Wire * output;

		Event tmpEvent = e.top();

		output = tmpEvent.getOutput();
		changed = output->doesChange(tmpEvent.getValue(), tmpEvent.getTime());
		output->setValue(tmpEvent.getValue(), tmpEvent.getTime());

		// if the wire value changes, evaluate gates
		if(changed && !(tmpEvent.getTime() > simTime)) {
			Gate * tmpGate;
			Event gateEvent(-1, -1, nullptr);
			int index = 0;
			while(true){
				tmpGate = output->getGate(index++);
				if (tmpGate != nullptr) {
					gateEvent = tmpGate->evaluate(tmpEvent.getTime());
					e.push(gateEvent);
				}
				else {
					break;
				}
			}
		}
		e.pop();
	}
}

// print each wire's trace
void Simulation::print(int simTime)
{
	int lastTime = 0;
	int tmpTime = 0;
	// iterate through wires, finding wire with last event time
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		if((**i).getLast() > lastTime) {
			lastTime = (**i).getLast();
		}
	}


	cout << "\n\nWire Traces: \n";
	// now iterate through wires, printing each of them
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		(**i).setLast(lastTime);
		(**i).setPrintLen(simTime);
		cout << **i;
	}

	int t = 0;
	cout << setw(6) << "TIME: ";
	while(t < simTime && t <= lastTime) {
		cout << setfill('.') << setw(5) << left << t;
		t += 5;
	}
	cout << t << endl;
}

// iterate through wires vector and find wire with provided number; if wire does
// not exist, create a new one
Wire * Simulation::findWire(int n)
{
	for (auto i = wires.begin(); i != wires.end(); ++i) {
		if (n == (**i).getNumber()) return *i;
	}

	// if wire does not exist, create it, instantiating as an intermediary wire
	Wire * tmpWire = new Wire(n, false);
	wires.push_back(tmpWire);
	return tmpWire;
}

int Simulation::getDelay(string d)
{
	d.resize(d.size() - 2);
	return atoi(d.c_str());
}

