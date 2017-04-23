#include "NotGate.h"

using namespace std;

NotGate::NotGate(int d, Wire* wire1, Wire* wire2) {
	delay = d;
	in1 = wire1;
	out = wire2;
}

Event NotGate::evaluate(int evTime) {
	if (in1->getValue(evTime) == 0) {
		if (out->getValue(evTime + delay) != 0) {
			return Event(-1, 0, evTime + delay, out);
		}
	}
	else{
		if (out->getValue(evTime + delay) != 1) {
			return Event(-1, 1, evTime + delay, out);
		}
	}
}

int NotGate::getDelay()
{
	return delay;
}
