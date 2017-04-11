#ifndef XNOR
#define XNOR
#include "gate.h"
#include "event.h"
#include "wire.h"

class xnorGate : public gate {
	xnorGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !XNOR
