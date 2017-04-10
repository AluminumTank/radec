#include "wire.h"

wire::wire(int number, bool io, string inName)
{
	wireNumber = number;
	isInput = io;
	name = inName;
	value = -1;
	lastEvent = 0;
}

int wire::getValue(int time) const
{
	return history[time];
}

void wire::setValue(int newValue, int setTime)
{
	while (setTime < 60 && 
	  (history[setTime] == -1 || history[setTime] == history[setTime+1])) {
		history[setTime] = newValue;
		if (lastEvent < setTime) {
			lastEvent = setTime;
		}
		setTime++;
	}
}

int wire::getNumber() const
{
	return wireNumber;
}

void wire::addGate(gate * newGate)
{
	gates.push_back(newGate);
}
