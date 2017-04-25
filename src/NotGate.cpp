#include "NotGate.h"

using namespace std;

NotGate::NotGate(int d, Wire* wire1, Wire* wire2) {
	delay = d;
	in1 = wire1;
	out = wire2;
}

Event NotGate::evaluate(int evTime) {
	if (in1->getValue(evTime) == 1) {
			return Event(0, evTime + delay, out);
	}else if (in1->getValue(evTime) == 0) {
			return Event(1, evTime + delay, out);
	}
	else {
		return Event(-1, evTime + delay, out);
	}
}

int NotGate::getDelay()
{
	return delay;
}
