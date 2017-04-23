#include "gate.h"

Gate::Gate()
{
}

void Gate::setOut(int newValue, int setTime)
{
	out->setValue(newValue, setTime);
}
