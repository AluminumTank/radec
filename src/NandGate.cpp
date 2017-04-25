#include "NandGate.h"

NandGate::NandGate(int d, Wire * wire1, Wire * wire2, Wire * wire3)
{
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

Event NandGate::evaluate(int evTime)
{
	if (in1->getValue(evTime) == 0 || in2->getValue(evTime) == 0) {
		return Event(-1, 1, evTime + delay, out);
	}
	else {
		return Event(-1, 0, evTime + delay, out);
	}
}

int NandGate::getDelay()
{
	return delay;
}
