#ifndef EVENT
#define EVENT


class event {
	public:
		event(int num, int value, int setTime, int wire);
		bool operator<(const event &e1);
	private:
		int evNum, evValue, evTime, wireNum;
};

#endif // !EVENT
