#ifndef OR
#define OR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

using namespace std;

class OrGate : public Gate {
	public:
		OrGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !OR
