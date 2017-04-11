#ifndef NOR
#define NOR
#include "gate.h"
#include "event.h"
#include "wire.h"

class norGate : public gate {
	norGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !NOR
