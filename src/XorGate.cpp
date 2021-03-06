#include "XorGate.h"

using namespace std;

XorGate::XorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3) {
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

// generate an event based on changes in the Gate's inputs
Event XorGate::evaluate(int evTime) {
	if (in1->getValue(evTime) != -1 && in2->getValue(evTime) != -1) {
		if (in1->getValue(evTime) != in2->getValue(evTime)) {
			return Event(1, evTime + delay, out);
		}
		else {
			return Event(0, evTime + delay, out);
		}
	}
	else {
		return Event(-1, evTime + delay, out);
	}
}

int XorGate::getDelay()
{
	return delay;
}
