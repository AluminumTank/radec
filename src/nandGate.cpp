#include "nandGate.h"

nandGate::nandGate(int d, wire * wire1, wire * wire2, wire * wire3)
{
	in1 = wire1;
	in2 = wire2;
	out = wire3;
	delay = d;
}

int nandGate::evaluate(int time)
{
	if (in1->getValue(time) == 0 || in2->getValue(time) == 0) {
		out->setValue(1, time + delay);
		return 1;
	}
	else if{
		out->setValue(0, time + delay);
		return 0;
	}
}