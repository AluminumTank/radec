#include "NorGate.h"

using namespace std;

NorGate::NorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3) {
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}

Event NorGate::evaluate(int evTime) {
	if (in1->getValue(evTime) == 1 || in2->getValue(evTime) == 1) {
		return Event(0, evTime + delay, out);
	}
	else if (in1->getValue(evTime) == 0 && in2->getValue(evTime) == 0) {
		return Event(1, evTime + delay, out);
	}
	else{
		return Event(-1, evTime + delay, out);
	}
}

int NorGate::getDelay()
{
	return delay;
}
