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
	int tmp;
	if (historyTimes.size() == 0 || wantedTime < historyTimes[0]) {
		return -1;
	}
	else {
		for (auto i = historyTimes.begin(); i != historyTimes.end(); i++) {
			if (*i > wantedTime) {
				tmp = i - historyTimes.begin();
				return historyValues[tmp - 1];
			}
		}
		return *(historyValues.end()-1);
	}
}

char Wire::getChar(int wantedTime) const
{
	if (getValue(wantedTime) == -1) {
		return 'x';
	}
	else if (getValue(wantedTime) == 0) {
		return '_';
	}
	else {
		return '-';
	}
}

void Wire::setValue(int newValue, int setTime)
{
	if (doesChange(newValue, setTime)) {
		historyTimes.push_back(setTime);
		historyValues.push_back(newValue);
		if (lastEvent < setTime) {
			lastEvent = setTime;
		}
	}
}

bool Wire::doesChange(int newValue, int setTime) {
	return getValue(setTime) != newValue;
}

void Wire::convertToIO(string newName)
{
	name = newName;
	isPrint = true;
}

Gate * Wire::getGate(int index) const
{
	if (index < gates.size()) {
		return gates[index];
	}
	return nullptr;
}

void Wire::setLast(int last)
{
	lastEvent = last;
}

void Wire::setPrintLen(int len)
{
	printLen = len;
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

int Wire::getLast() const
{
	return lastEvent;
}

ostream & operator<<(ostream & out, const Wire & c)
{
	if (c.isPrint) {
		int len = 0;
		out << setw(6) << c.name + ": ";
			while (len <= c.printLen && len <= c.lastEvent)
			{
				out << setw(0) << c.getChar(len++);
			}
			out << endl << endl;
	}
	return out;
}
