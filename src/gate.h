#ifndef GATE
#define GATE
class wire;

class gate {
	public:
		gate();
		virtual void evaluate() = 0;

	protected:
		wire *in1, *in2, *out;
		priority_queue<event> *e;
		int delay;
		priority_queue<event> *e;
};

#endif // !GATE
