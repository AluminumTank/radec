#ifndef AND
#define AND
#include "gate.h"
#include "event.h"
#include "wire.h"

class andGate : public gate {
	public:
		andGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
		void evaluate(int evTime);
		int getDelay();
};

#endif // !AND
