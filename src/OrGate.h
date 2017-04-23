#ifndef OR
#define OR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

class OrGate : public Gate {
	public:
	OrGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
	void evaluate(int evTime);
	int getDelay();
};

#endif // !OR
