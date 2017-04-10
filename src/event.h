#ifndef EVENT
#define EVENT

class event {
	public:
		event(event, value, setTime, wire);
		bool operator<(const event &e1, const event &e2);
	private:
		int evNum, evValue, evTime, wireNum;
};

#endif // !EVENT
