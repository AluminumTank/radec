#ifndef XNOR
#define XNOR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

class XnorGate : public Gate {
	public:
	XnorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
	void evaluate(int evTime);
	int getDelay();
};

#endif // !XNOR
