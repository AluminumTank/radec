#ifndef XOR
#define XOR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

using namespace std;

class XorGate : public Gate {
	public:
		XorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !XOR
