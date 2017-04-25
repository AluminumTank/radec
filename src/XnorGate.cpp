#include "XnorGate.h"

using namespace std;

XnorGate::XnorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3) {
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

Event XnorGate::evaluate(int evTime) {
	if (in1->getValue(evTime) != -1 && in2->getValue(evTime) != -1) {
		if (in1->getValue(evTime) == in2->getValue(evTime)) {
			return Event(-1, 1, evTime + delay, out);
		}
		else {
			return Event(-1, 0, evTime + delay, out);
		}
	}
}

int XnorGate::getDelay()
{
	return delay;
}
