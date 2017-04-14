#include "event.h"

event::event(int num, int value, int setTime, wire * output){
	evNum = num;
	evValue = value;
	evTime = setTime;
	out = output;
}

bool operator<(const event &e1, const event &e2) {
	if(e1.evTime == e2.evTime) {
		return e1.evNum > e2.evNum;
	}
	return e1.evTime > e2.evTime;
}

