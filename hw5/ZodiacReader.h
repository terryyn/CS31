#ifndef ZodiacReader_H
#define ZodiacReader_H
#include <iostream>
#include <string>
#include "Date.h"

class ZodiacReader
{
private:
	Date mDate;
public:
	ZodiacReader();
	enum Sign {
		ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO,
		LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES
	};

	ZodiacReader(Date date);

	Sign checkSign();

	bool onCusp();

	Sign cuspSign();

	string stringifySign(Sign ZodiacReader);
};

#endif#pragma once
#pragma once
