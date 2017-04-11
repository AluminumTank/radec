#ifndef NOT
#define NOT

class not : public gate {
	notGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2);
	void evaluate(int evTime);
};

#endif // !NOT
