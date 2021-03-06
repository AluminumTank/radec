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

		void setValue(int newValue, int setTime);
		bool doesChange(int newValue, int setTime);
		void convertToIO(string newName);
		Gate* getGate(int index) const;
		void setLast(int last);
		void setPrintLen(int);

		friend ostream& operator<<(ostream &out, const Wire &c);

	private:
		int WireNumber, value, lastEvent, printLen;
		vector<int> historyTimes;
		vector<int> historyValues;
		string name;
		bool isPrint;
		vector<Gate*> gates;
};

#endif // !WIRE
