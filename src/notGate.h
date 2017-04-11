#ifndef NOT
#define NOT
#include "gate.h"
#include "wire.h"
#include "event.h"

class not : public gate {
	notGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2);
	void evaluate(int evTime);
};

#endif // !NOT
