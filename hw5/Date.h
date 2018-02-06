#include<iostream>
#include<string>
#include<cassert>
#ifndef Date_h
#define Date_h
using namespace std;

class Date
{
public:
	Date();
	Date(int month, int day);
	int getMonth() const;  //use const for accessor function to make sure it just accesses the value
	int getDay() const;
	~Date();     //create a desctructor here just in case
private:
	int mMonth;
	int mDay;
};

#endif 

#pragma once
