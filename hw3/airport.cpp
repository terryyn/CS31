#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isWellFormedAirportString(string commands);
double ontimeArrivalPercentage(string commands, string airlinecode);
string toLower(string s);
bool checkAirline(string a, int positionA);
bool checkNumber(string b, int & positionB);
bool checkTime(string c, int positionC);

bool isWellFormedAirportString(string commands)
{
	bool result = true;
	commands = toLower(commands);
	int position = 0;
	while (position < commands.size()) {
		if (!checkAirline(commands, position))
			result = false;
		position = position + 2;
		if (!checkNumber(commands, position))
			result = false;
		if (!checkTime(commands, position))
			result = false;
		position++;
		if (!checkNumber(commands, position))
			result = false;

	}
	return(result);
}

double ontimeArrivalPercentage(string commands, string airlinecode)
{
	commands = toLower(commands);
	airlinecode = toLower(airlinecode);
	int total = 0;
	int onTime = 0;
	if (!isWellFormedAirportString(commands))
		return -1;
	if (!checkAirline(airlinecode, 0))
		return -1;
		
	for (int i = 0; i < commands.size() - 1; i++) {   //-1 to make sure that there is no undefined behabior
		string temp;
		temp += commands[i];
		temp += commands[i + 1];
		if (temp == airlinecode)
		{
			int use = i + 2;
			checkNumber(commands, use);
			if (commands[use] == '+') {
				int temp = 0;
				for (int n = use + 1; n < commands.size(); n++) {
					if (isdigit(commands[n]))
						temp++;
					else
						break;
				}
				switch (temp)
				{
				case 1:
					onTime++;
					break;
				case 2:
					if (commands[use + 1] <= '1' && commands[use + 2] < '5')
						onTime++;
					break;
				case 3:
					break;
				default:
					break;
				}
			}
			else
				onTime++;


			total++;
		}

	}
	if (total == 0)
		return 0;
	return(onTime*1.0 / total);

}

string toLower(string s)
{
	string temp;
	for (int i = 0; i < s.size(); i++) {
		temp += tolower(s[i]);

	}
	return temp;
}

//check the airline code
bool checkAirline(string a, int positionA)
{
	a = toLower(a);
	string temp;
	assert(positionA < a.size() - 1);
	if (positionA >= a.size()-1)
	{
		return false;
	}
	else
	{
		temp += a[positionA];
		temp += a[positionA + 1];
		if (temp == "aa" || temp == "ua" || temp == "dl" || temp == "sw" || temp == "al" || temp == "va")
			return true;
		else
			return false;
	}
}

//check if the number is between 0 and 999
bool checkNumber(string b, int & positionB)
{
	int temp = 0;
	for (int i = positionB; i < b.size(); i++) {  
		if (isdigit(b[i]))
			temp++;
		else
			break;   //find how many consecutive numbers are here for there?
	}
	switch (temp)
	{
	case 1:
		positionB = positionB + 1;
		break;
	case 2:
		positionB = positionB + 2;
		break;
	case 3:
		positionB = positionB + 3;
		break;
	default:
		return false;;// it will be false if the temp is not 1,2,3
	}
	return true;
}

bool checkTime(string c, int positionC)
{
	if (c[positionC] != '+'&& c[positionC] != '-')
		return false;
	return true;
}

int main()
{
	string commands;
	cin >> commands;
	if (isWellFormedAirportString(commands))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	string test;
	cin >> test;
	cout << ontimeArrivalPercentage(commands, test) << endl;
	return 0;
}
