#ifndef NAND
#define NAND
#include "gate.h"
#include "event.h"
#include "wire.h"

using namespace std;

class nandGate : public gate {
	public:
		nandGate(int d, wire* wire1 = nullptr, wire* wire2 = nullptr, wire* wire3 = nullptr);
		int evaluate(int time);
};

#endif // !NAND
