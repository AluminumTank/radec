#ifndef XNOR
#define XNOR

class xnorGate : public gate {
	xnorGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !XNOR
