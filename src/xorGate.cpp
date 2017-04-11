#include "xorGate.h"

using namespace std;

xorGate::xorGate(priority_queue<event> *eQueue, int d, wire* wire1,
	wire* wire2, wire* wire3) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

void xorGate::evaluate(int evTime) {
	//TODO
}
