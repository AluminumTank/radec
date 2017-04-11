#include "notGate.h"

using namespace std;

notGate::notGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	out = wire2;
	
}

void notGate::evaluate(int evTime) {
	if (in1->getValue(evTime) == 0) {
		if (out->getValue(evTime + delay) != 0) {
			e->push(event(e->size, 0, evTime + delay, out));
			out->setValue(0, evTime + delay);
		}
	}
	else{
		if (out->getValue(evTime + delay) != 1) {
			e->push(event(e->size, 1, evTime + delay, out));
			out->setValue(1, evTime + delay);
		}
	}
}
