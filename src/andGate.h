#ifndef AND
#define AND

class andGate : public gate {
	public:
		andGate(wire* wire1 = nullptr, wire* wire2 = nullptr,
			wire* wire3 = nullptr);
		int evaluate(int evTime);
};

#endif // !AND
