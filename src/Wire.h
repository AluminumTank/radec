#ifndef WIRE
#define WIRE

#include <vector>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;

class Gate;

class Wire {
	public:
		Wire(int number, bool io, string inName = "");

		void addGate(Gate* newGate);

		int getValue(int wantedTime) const;
		char getChar(int wantedTime) const;
		int getNumber() const;
		string getName() const;
		int getLast() const;

		bool setValue(int newValue, int setTime);
		void convertToIO(string newName);
		Gate* getGate(int index);
		void setLast(int last);

		friend ostream& operator<<(ostream &out, const Wire &c);

	private:
		int WireNumber, value, lastEvent;
		vector<int> historyTimes;
		vector<int> historyValues;
		string name;
		bool isPrint;
		vector<Gate*> gates;
};

#endif // !WIRE
