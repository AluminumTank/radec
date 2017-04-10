#include "andGate.h"

using namespace std;

andGate::andGate(wire* wire1 = nullptr, wire* wire2 = nullptr,
		wire* wire3 = nullptr) : in1(wire1), in2(wire2), out(wire3) {}

int andGate::evaluate(int evTime) {
	int val1 = in1->getValue();
	int val2 = in2->getValue();
	if(val1 != -1 && val2 != -1) {
		return val1 && val2;
	}
}
