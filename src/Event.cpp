#include "Event.h"

// static integer to keep track of current number of events
int Event::numOfEvents = 0;

Event::Event(int value, int setTime, Wire * output){
	evNum = numOfEvents++;
	evValue = value;
	evTime = setTime;
	out = output;
}

int Event::getValue() const
{
	return evValue;
}

int Event::getTime() const
{
	return evTime;
}

Wire * Event::getOutput() const
{
	return out;
}

void Event::setNum(int num)
{
	evNum = num;
}

// < operator so that Event can be used in a priority_queue
bool operator<(const Event &e1, const Event &e2) {
	if(e1.evTime == e2.evTime) {
		return e1.evNum > e2.evNum;
	}
	return e1.evTime > e2.evTime;
}
