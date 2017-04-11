#ifndef NOT
#define NOT
#include "gate.h"
#include "wire.h"
#include "event.h"

class notGate : public gate {
	notGate(int delay, wire* wire1 = nullptr, wire* wire2 = nullptr);
	int evaluate();
};

#endif // !NOT
