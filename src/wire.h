#ifndef WIRE
#define WIRE

#include <vector>
#include <queue>
#include <string>

class gate;

class wire {
	public:
		wire(int number, bool io, string name = "");

		int getState() const;
		void setState(bool newValue, int setTime);

		void addGate(gate* newGate);

	private:
		int wireNumber, value;
		string name;
		bool isInput;
		vector<gate*> gates;
};

#endif // !WIRE
