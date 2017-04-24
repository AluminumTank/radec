#include "Wire.h"

Wire::Wire(int number, bool io, string inName)
{
	WireNumber = number;
	isPrint = io;
	name = inName;
	value = -1;
	lastEvent = 0;
}

int Wire::getValue(int wantedTime) const
{
	if (historyTimes.size() == 0 || wantedTime < historyTimes[0]) {
		return -1;
	}
	else {
		for (auto i = historyTimes.begin(); i != historyTimes.end(); i++) {
			if (*i > wantedTime) {
				return historyValues[i - 1 - historyTimes.begin()];
			}
		}
	}
}

void Wire::setValue(int newValue, int setTime)
{
	historyTimes.push_back(setTime);
	historyValues.push_back(newValue);
	if (lastEvent < setTime) {
		lastEvent = setTime;
	}
}

void Wire::convertToIO(string newName)
{
	name = newName;
	isPrint = true;
}

int Wire::getNumber() const
{
	return WireNumber;
}

void Wire::addGate(Gate * newGate)
{
	gates.push_back(newGate);
}

string Wire::getName() const
{
	return name;
}
