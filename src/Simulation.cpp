#include "Simulation.h"

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

		if (tmpType == "INPUT") {
			tmpWire = new Wire(tmp1, true, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "OUTPUT") {
			tmpWire = new Wire(tmp1, false, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "NOT") {
			in >> tmp2;
			tmpGate = new NotGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "AND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new AndGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NAND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new NandGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2), findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "OR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new OrGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new XorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new NorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XNOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new XnorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
	}
	return true;
}

bool parseVector(string fileName) {
	ifstream in;
	in.open(fileName + "_v.txt");
	if (in.fail()) {
		cerr << endl << fileName << "_v.txt could not be opened :(";
		return false;
	}

	string tmpString;
	int timeInt, valInt;

	// get rid of first line
	getline(in, tmpString);

	while(!in.eof()) {
		in >> tmpString;
		in >> tmpString;
		in >> timeInt;
		in >> valInt;

		for(auto i = wires.begin(); i != wires.end(); ++i) {
			if(i->getName() == tmpString) {
				tmpWire = i;
			}
		}

		e.push(Event(eventNum++, valInt, timeInt, tmpWire));
	}
}

void Simulation::simulate()
{
}

void Simulation::print()
{
}

Wire * Simulation::findWire(int n)
{
	for (auto i = wires.begin(); i != wires.end(); ++i) {
		if (n == (**i).getNumber()) return *i;
	}
	return nullptr;
}

int Simulation::getDelay(string d)
{
	d.resize(d.size() - 2);
	return atoi(d.c_str());
}
