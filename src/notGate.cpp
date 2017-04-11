#include "notGate.h"

using namespace std;

notGate::notGate(int gateDelay, wire* wire1 = nullptr, wire* wire2 = nullptr)
	: delay(gateDelay), in1(wire1), out(wire2) {}

notGate::evaluate() {
	int val = in1->getValue();

	if(val != -1) {
		return !val;
	}
}
