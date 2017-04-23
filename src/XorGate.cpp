#include "XorGate.h"

using namespace std;

XorGate::XorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3) {
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

Event XorGate::evaluate(int evTime) {
	if (in1->getValue(evTime) != -1 && in2->getValue(evTime) != -1) {
		if (in1->getValue(evTime) != in2->getValue(evTime)) {
			if (out->getValue(evTime + delay) != 1) {
				return Event(-1, 1, evTime + delay, out);
			}
		}
		else {
			if (out->getValue(evTime + delay) != 0) {
				return Event(-1, 0, evTime + delay, out);
			}
		}
	}
}

int XorGate::getDelay()
{
	return delay;
}
