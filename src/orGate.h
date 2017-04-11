#ifndef OR
#define OR

class xnorGate : public gate {
	orGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
	void evaluate(int evTime);
};

#endif // !OR
