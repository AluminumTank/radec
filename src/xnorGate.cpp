#include "xnorGate.h"

using namespace std;

xnorGate::xnorGate(priority_queue<event> *eQueue, int d, wire* wire1,
		wire* wire2, wire* wire3) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

void xnorGate::evaluate(int evTime) {
	//TODO
}
