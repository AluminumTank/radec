#include "Wire.h"

Wire::Wire(int number, bool io, string inName)
{
	WireNumber = number;
	isPrint = io;
	name = inName;
	value = -1;
	lastEvent = 0;
	history.insert(history.begin(), 60, -1);
}

int Wire::getValue(int time) const
{
	for (auto i = history.begin() + time; i != history.begin(); i--) {
		if (i[0] != -1) {
			return i[0];
		}
	}
	return -1;
}

void Wire::setValue(int newValue, int setTime)
{
	history[setTime] = newValue;
	if (lastEvent < setTime) {
		lastEvent = setTime;
	}
}

int Wire::getNumber() const
{
	return wireNumber;
}

void Wire::addGate(Gate * newGate)
{
	gates.push_back(newGate);
}
