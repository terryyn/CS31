//Project 2 
//Terry Ye   ID:004757414  1G
//Fare Calculator

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	double miles = 0;
	double time = 0;
	string type;    
	double fare;//declare the variables we need


	cout << "Customer Name: ";
	getline(cin, name);   //get the name 
	// problem here: has to press enter twice???----solved: delete cin.ignore here

	if (name == "") {
		cout << "--- You must enter a customer name.\n";
		return 1;
	}

	cout << "Miles to be driven: ";
	cin >> miles;
	//get the miles

	if (miles <= 0) {
		cout << "--- The mileage must be positive.\n";
		return 1;
	}

	cout << "Minutes to be driven: ";
	cin >> time;
	//get the time

	if (time <= 0) {
		cout << "--- The time must be positive.\n";
		return 1;
	}
	cout << "Ride Type: ";
	cin.ignore(10000, '\n');
	getline(cin, type);

	if (type != "Br-UberX" && type != "Br-UberXL") {
		cout << "--- The ride type is not valid.\n";
		return 1;
	}

	if (type == "Br-UberX") {
		fare = 0.15*time + 0.90*miles + 1.65;
		if (fare < 5.15) {
			fare = 5.15;
			}
	}
	
	if (type == "Br-UberXL") {
		fare = 0.30*time + 1.55*miles + 1.65;
		if (fare < 7.65) {
			fare = 7.65;
		}
	}

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "--- The fare for " << name << " is $" << fare << endl;
	return 0;
	

}