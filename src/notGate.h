#ifndef NOT
#define NOT
#include "gate.h"
#include "wire.h"
#include "event.h"

class notGate : public gate {
	public:
	notGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2);
	void evaluate(int evTime);
};

#endif // !NOT
