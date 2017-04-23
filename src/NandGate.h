#ifndef NAND
#define NAND
#include "Gate.h"
#include "Event.h"
#include "Wire.h"

using namespace std;

class NandGate : public Gate {
	public:
		NandGate(int d, Wire* wire1, Wire* wire2, Wire* wire3);
		void evaluate(int time);
		int getDelay();
};

#endif // !NAND
