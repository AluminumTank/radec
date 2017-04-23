#ifndef GATE
#define GATE

#include "Event.h"

class Wire;

class Gate {
	public:
		virtual Event evaluate(int) = 0;
		void setOut(int time, int value);
	protected:
		Wire *in1, *in2, *out;
		int delay;
};

#endif // !GATE
