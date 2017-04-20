#ifndef GATE
#define GATE

#include "event.h"

class wire;

class gate {
	public:
		gate();
		virtual void evaluate(int) = 0;

	protected:
		wire *in1, *in2, *out;
		priority_queue<event> *e;
		int delay;
};

#endif // !GATE
