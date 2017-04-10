#ifndef WIRE
#define WIRE

#include <vector>
#include <queue>
#include <string>

using namespace std;

class gate;

class wire {
	public:
		wire(int number, bool io, string inName = "");

		int getValue(int time) const;
		void setValue(int newValue, int setTime);

		int getNumber() const;
		void addGate(gate* newGate);

	private:
		int wireNumber, value, lastEvent;
		vector<int> history (60, -1);
		string name;
		bool isInput;
		vector<gate*> gates;
};

#endif // !WIRE
