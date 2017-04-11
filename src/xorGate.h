#ifndef XOR
#define XOR

class xorGate : public gate {
	xorGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !XOR
