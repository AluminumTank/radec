#ifndef NOT
#define NOT

class not : public gate {
	notGate(wire* wire1 = nullptr, wire* wire2 = nullptr);
	int evaluate();
};

#endif // !NOT
