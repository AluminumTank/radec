#include "AndGate.h"

using namespace std;

AndGate::AndGate(int d, Wire* wire1, Wire* wire2, Wire* wire3) {
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}
int AndGate::evaluate(int evTime) {
	if (in1->getValue(evTime) == 0 || in2->getValue(evTime) == 0) {
		if (out->getValue(evTime + delay) != 0) {
			e->push(Event(e->size, 0, evTime + delay, out));
			out->setValue(0, evTime + delay);
		}
	}
	else if(in1->getValue(evTime) == 1 && in2->getValue(evTime) == 1){
		if (out->getValue(evTime + delay) != 1) {
			e->push(Event(e->size, 1, evTime + delay, out));
			out->setValue(1, evTime + delay);
		}
	}
}

int AndGate::getDelay()
{
	return delay;
}
