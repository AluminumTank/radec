#ifndef EVENT
#define EVENT

using namespace std;
#include "Wire.h"

class Event {
	public:
		Event(int num, int value, int setTime, Wire * output);
		friend bool operator<(const Event &e1, const Event &e2);
	private:
		int evNum, evValue, evTime;
		Wire *out;
};

#endif // !EVENT