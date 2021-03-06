#ifndef NOR
#define NOR
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

using namespace std;

class NorGate : public Gate {
	public:
		NorGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		Event evaluate(int evTime);
		int getDelay();
};

#endif // !NOR
