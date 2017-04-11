#include "orGate.h"

using namespace std;

orGate::orGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
		wire* wire3) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

void orGate::evaluate(int evTime) {
	//TODO
}
