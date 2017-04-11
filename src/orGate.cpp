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
	if (in1->getValue(evTime) == 1 || in2->getValue(evTime) == 1) {
		if (out->getValue(evTime + delay) != 1) {
			e->push(event(e->size, 1, evTime + delay, out));
			out->setValue(1, evTime + delay);
		}
	}
	else if (in1->getValue(evTime) == 0 && in2->getValue(evTime) == 0) {
		if (out->getValue(evTime + delay) != 0) {
			e->push(event(e->size, 0, evTime + delay, out));
			out->setValue(0, evTime + delay);
		}
	}
}
