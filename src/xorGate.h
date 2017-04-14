#ifndef XOR
#define XOR
#include "gate.h"
#include "event.h"
#include "wire.h"

class xorGate : public gate {
	public:
	xorGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !XOR
