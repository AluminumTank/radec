#ifndef OR
#define OR

class orGate : public gate {
	orGate(wire* wire1 = nullptr, wire* wire2 = nullptr, wire* wire3 = nullptr);
	int evaluate();
};

#endif // !OR
