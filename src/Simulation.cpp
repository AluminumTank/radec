#include "Simulation.h"

bool Simulation::parse(string fileName)
{
	ifstream in;
	circuit.open(fileName + ".txt");
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
		tmpType << in;

		tmpString << in;
		tmp1 << in;
		if (tmpType == "INPUT") {
			tmpWire = new wire(tmp1, true, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "OUTPUT") {
			tmpWire = new wire(tmp1, false, tmpString);
			wires.push_back(tmpWire);
		}
		else if (tmpType == "NOT") {
			tmp2 << in;
			tmpGate = new notGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "AND") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new andGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NAND") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new nandGate(getDelay(tmpString), findWire(tmp1),
				findWire(tmp2), findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "OR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new orGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XOR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new xorGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "NOR") {
			tmp2 << in;
			tmp3 << in;
			tmpGate = new norGate(getDelay(tmpString), findWire(tmp1), findWire(tmp2),
				findWire(tmp3));
			gates.push_back(tmpGate);
		}
		else if (tmpType == "XNOR") {
			tmp2 << in;
			tmp3 << in;
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
