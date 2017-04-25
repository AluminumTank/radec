#include "Simulation.h"
#include <iostream>
#include <iomanip>

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

	while (!in.eof()) {
		in >> tmpType;
		in >> tmpString;
		in >> tmp1;

		if (tmpType == "INPUT" || tmpType == "OUTPUT") {
			tmpWire = findWire(tmp1);
			tmpWire->convertToIO(tmpString);
		}
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

bool Simulation::parseVector(string fileName) {
	ifstream in;
	in.open(fileName + "_v.txt");
	if (in.fail()) {
		cerr << endl << fileName << "_v.txt could not be opened :(";
		return false;
	}

	string tmpString;
	int timeInt, valInt;
	Wire *tmpWire = nullptr;

	// get rid of first line
	getline(in, tmpString);

	while(!in.eof()) {
		in >> tmpString;
		in >> tmpString;
		in >> timeInt;
		in >> valInt;

		for(auto i = wires.begin(); i != wires.end(); ++i) {
			if((**i).getName() == tmpString) {
				tmpWire = *i;
			}
		}

		e.push(Event(eventNum++, valInt, timeInt, tmpWire));
	}
}

void Simulation::simulate() {
	// loop through event queue
	while(!e.empty()) {
		bool doesChange;
		Wire * output;

		Event tmpEvent = e.top();
		e.pop();

		output = tmpEvent.getOutput();
		doesChange = output->setValue(tmpEvent.getValue(), tmpEvent.getTime());

		// if the wire value changes, evaluate gates
		if(doesChange) {
			Gate * tmpGate;
			Event gateEvent(-1, -1, -1, nullptr);
			int index = 0;
			while(true){
				tmpGate = output->getGate(index++);
				if (tmpGate != nullptr) {
					gateEvent = tmpGate->evaluate(tmpEvent.getTime());
					gateEvent.setNum(eventNum++);
					e.push(gateEvent);
				}
				else {
					break;
				}
			}
		}
	}
}

void Simulation::print()
{
	int lastTime = 0;
	int tmpTime = 0;
	// iterate through wires, finding wire with last event time
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		if((**i).getLast() > lastTime) {
			lastTime = (**i).getLast();
		}
	}

	// now iterate through wires, printing each of them
	for(auto i = wires.begin(); i != wires.end(); ++i) {
		(**i).setLast(lastTime);
		cout << **i;
	}

	int t = 0;
	cout << setw(10) << "TIME";
	while(t <= 60 && t <= lastTime) {
		cout << setw(5) << t;
		t += 5;
	}
}

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
