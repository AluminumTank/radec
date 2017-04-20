#ifndef OR
#define OR
#include "gate.h"
#include "event.h"
#include "wire.h"

class orGate : public gate {
	public:
	orGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
	int getDelay();
};

#endif // !OR
