#include "notGate.h"

using namespace std;

notGate::notGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2) {
	e = eQueue;
	delay = d;
	in1 = wire1;
	out = wire2;
	
}

void notGate::evaluate(int evTime) {
	int val = in1->getValue();

	if(val != -1) {
	}
}
