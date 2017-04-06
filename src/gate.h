#ifndef GATE
#define GATE

class gate {
	public:
		gate(wire* wire1 = nullptr, wire* wire2 = nullptr, wire* wire3 = nullptr);
		virtual int getOutput() = 0;
	protected:
		wire* in1, in2, out;
	/* TODO
	 * delay
	 * type
	 */
};

#endif // !GATE
