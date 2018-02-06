#include "Date.h"
#include <cassert>

Date::Date()
{
	mMonth = 0;
	mDay = 0;
}
Date::Date(int month, int day)
{
	mMonth = month;
	mDay = day;
	assert(month < 13 && month>0);
	assert(day > 0 && day < 32);
}

int Date::getDay() const
{
	return mDay;
}

int Date::getMonth() const
{
	return mMonth;
}

Date::~Date()
{
	//do nothing for destructor
}

