#ifndef AND
#define AND
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

class AndGate : public Gate {
	public:
		AndGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !AND
