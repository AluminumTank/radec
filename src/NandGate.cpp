#include "NandGate.h"

NandGate::NandGate(int d, Wire * wire1, Wire * wire2, Wire * wire3)
{
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

void NandGate::evaluate(int evTime)
{
	if (in1->getValue(evTime) == 0 || in2->getValue(evTime) == 0) {
		if (out->getValue(evTime + delay) != 1) {
			e->push(event(e->size, 1, evTime + delay, out));
			out->setValue(1, evTime + delay);
		}
	}
	else {
		if (out->getValue(evTime + delay) != 0) {
			e->push(event(e->size, 0, evTime + delay, out));
			out->setValue(0, evTime + delay);
		}
	}
}

int NandGate::getDelay()
{
	return delay;
}
