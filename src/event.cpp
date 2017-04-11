#include "event.h"

event::event(int num, int value, int setTime, wire * output){
	evNum = num;
	evValue = value;
	evTime = setTime;
	out = output;
}

bool event::operator<(const event &e1) {
	if(evTime == e1.evTime) {
		return evNum > e1.evNum;
	}
	return evTime > e1.evTime;
}

