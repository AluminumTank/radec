#ifndef NOT
#define NOT
#include "Gate.h"
#include "Wire.h"
#include "Event.h"

class NotGate : public Gate {
	public:
		NotGate(int d, Wire* wire1, Wire* wire2);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !NOT
