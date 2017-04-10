#include "event.h"

using namespace std;

event::event(int num, int value, int setTime, int wire) : evNum(num), evValue(value),
	evTime(setTime), wireNum(wire) {}

bool event::operator<(const event &e1) {
	if(evTime == e1.evTime) {
		return evNum > e1.evNum;
	}
	return evTime > e1.evTime;
}
