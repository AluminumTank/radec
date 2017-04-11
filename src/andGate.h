#ifndef AND
#define AND

class andGate : public gate {
	public:
		andGate(priority_queue<event> *eQueue, int d, wire* wire1, wire* wire2,
			wire* wire3);
		int evaluate(int evTime);
};

#endif // !AND
