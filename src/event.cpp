#include "event.h"

using namespace std;

event::event(event, value, setTime, wire) : evNum(event), evValue(value),
	evTime(setTime), wireNum(wire) {}

// operator overload so that priority_queue will function correctly
bool event::operator<(const event &e1, const event &e2) {
	if(e1.evTime == e2.evTime) {
		return e1.evNum > e2.evNum;
	}
	return e1.evTime > e2.evTime;
}
