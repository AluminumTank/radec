#ifndef WIRE
#define WIRE

#include <vector>
#include <queue>
#include <string>

using namespace std;

class Gate;

class Wire {
	public:
		Wire(int number, bool io, string inName = "");

		int getValue(int time) const;
		void setValue(int newValue, int setTime);

		int getNumber() const;
		void addGate(Gate* newGate);

	private:
		int wireNumber, value, lastEvent;
		vector<int> history;
		string name;
		bool isPrint;
		vector<Gate*> gates;
};

#endif // !WIRE
