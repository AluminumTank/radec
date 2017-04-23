#ifndef XNOR
#define XNOR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

using namespace std;

class XnorGate : public Gate {
	public:
		XnorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !XNOR
