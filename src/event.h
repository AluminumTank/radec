#ifndef EVENT
#define EVENT

using namespace std;
#include "wire.h"

class event {
	public:
		event(int num, int value, int setTime, wire * output);
		bool operator<(const event &e1);
	private:
		int evNum, evValue, evTime;
		wire *out;
};

#endif // !EVENT
