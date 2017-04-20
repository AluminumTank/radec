#include "Simulation.h"

bool Simulation::parseCircuit(string fileName)
{
	ifstream in;
	in.open(fileName + ".txt");
	if (in.fail()) {
		cerr << endl << fileName << ".txt could not be opened :(";
		exit(1);
	}

	string tmpString, tmpType;
	int tmp1, tmp2, tmp3;
	wire *tmpWire;
	gate *tmpGate;
	getline(in, tmpString);

	while (!in.eof()) {
		in >> tmpType;

		in >> tmpString;
		in >> tmp1;

		if (tmpType == "INPUT") {
			tmpWire = new wire(tmp1, true, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "OUTPUT") {
			tmpWire = new wire(tmp1, false, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "NOT") {
			in >> tmp2;
			tmpGate = new notGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "AND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new andGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NAND") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new nandGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2), findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "OR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new orGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new xorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new norGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XNOR") {
			in >> tmp2;
			in >> tmp3;
			tmpGate = new xnorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
	}
}

void Simulation::simulate()
{
}

void Simulation::print()
{
}

wire * Simulation::findWire(int n)
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
