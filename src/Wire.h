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

		void addGate(Gate* newGate);

		int getValue(int wantedTime) const;
		int getNumber() const;
		string getName() const;

		void setValue(int newValue, int setTime);
		void convertToIO(string newName);

	private:
		int WireNumber, value, lastEvent;
		vector<int> historyTimes;
		vector<int> historyValues;
		string name;
		bool isPrint;
		vector<Gate*> gates;
};

#endif // !WIRE
