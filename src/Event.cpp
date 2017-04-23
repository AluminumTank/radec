#include "Event.h"

Event::Event(int num, int value, int setTime, Wire * output){
	evNum = num;
	evValue = value;
	evTime = setTime;
	out = output;
}

bool operator<(const Event &e1, const Event &e2) {
	if(e1.evTime == e2.evTime) {
		return e1.evNum > e2.evNum;
	}
	return e1.evTime > e2.evTime;
}

