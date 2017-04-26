#ifndef GATE
#define GATE

#include "Event.h"

class Wire;

// this class provides a base class for all other Gate classes (provided in
// other files)
class Gate {
	public:
		virtual Event evaluate(int) = 0;
		void setOut(int time, int value);
	protected:
		Wire *in1, *in2, *out;
		int delay;
};

#endif // !GATE
