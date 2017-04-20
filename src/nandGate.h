#ifndef NAND
#define NAND
#include "gate.h"
#include "event.h"
#include "wire.h"

using namespace std;

class nandGate : public gate {
	public:
		nandGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2, wire* wire3);
		void evaluate(int time);
		int getDelay();
};

#endif // !NAND
