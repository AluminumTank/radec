#include "NotGate.h"

using namespace std;

NotGate::NotGate(int d, Wire* wire1, Wire* wire2) {
	delay = d;
	in1 = wire1;
	out = wire2;
	
}

void NotGate::evaluate(int evTime) {
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

int NotGate::getDelay()
{
	return delay;
}
