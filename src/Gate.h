#ifndef GATE
#define GATE

#include "Event.h"

class Wire;

class Gate {
	public:
		virtual Event evaluate(int) = 0;

	protected:
		Wire *in1, *in2, *out;
		int delay;
};

#endif // !GATE
