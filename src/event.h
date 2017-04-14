#ifndef EVENT
#define EVENT

using namespace std;
#include "wire.h"

class event {
	public:
		event(int num, int value, int setTime, wire * output);
		friend bool operator<(const event &e1, const event &e2);
	private:
		int evNum, evValue, evTime;
		wire *out;
};

#endif // !EVENT
