#include "andGate.h"

using namespace std;

andGate::andGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
  wire* wire3) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	in2 = wire2;
	out = wire3;
}
int andGate::evaluate(int evTime) {
	int val1 = in1->getValue(evTime);
	int val2 = in2->getValue(evTime);
	if(val1 != -1 && val2 != -1) {
		return val1 && val2;
	}
}
