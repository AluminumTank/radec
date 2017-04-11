#include "nandGate.h"

nandGate::nandGate(priority_queue<event> *eQueue, int d, wire * wire1, wire * wire2, wire * wire3)
{
	in1 = wire1;
	in2 = wire2;
	out = wire3;
	delay = d;
	e = eQueue;
}

void nandGate::evaluate(int time)
{
	if (in1->getValue(time) == 0 || in2->getValue(time) == 0) {
		if (out->getValue(time + delay) != 1) {
			e->push(event(e->size, 1, time + delay, out));
			out->setValue(1, time + delay);
		}
	}
	else {
		e->push(event(e->size, 0, time + delay, out));
		out->setValue(0, time + delay);
	}
}