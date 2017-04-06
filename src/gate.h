#ifndef GATE
#define GATE
class wire;

class gate {
	public:
		gate();
		virtual int evaluate() = 0;

	protected:
		wire* in1, in2, out;
		int delay;
};

#endif // !GATE
