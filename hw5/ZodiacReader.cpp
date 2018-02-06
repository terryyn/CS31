#include "ZodiacReader.h"
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

ZodiacReader::ZodiacReader()
{
	//default constructor
}

ZodiacReader::ZodiacReader(Date date)
{
	mDate = date;
}


ZodiacReader::Sign ZodiacReader::checkSign()   // has to be ZodiacReader::Sign  !!!!
{
	int month = mDate.getMonth();
	int day = mDate.getDay();
	switch (month)
	{
	case 1:
		if (day <= 19 && day >= 1)
			return CAPRICORN;
		else if (day <= 31)
			return AQUARIUS;
		break;
	case 2:
		if (day <= 18 && day >= 1)
			return AQUARIUS;
		else if (day >= 19 && day <= 29)
			return PISCES;
		break;
	case 3:
		if (day <= 20 && day >= 1)
			return PISCES;
		else if (day >= 21 && day <= 31)
			return ARIES;
		break;
	case 4:
		if (day <= 19 && day >= 1)
			return ARIES;
		else if (day >= 20 && day <= 30)
			return TAURUS;
		break;
	case 5:
		if (day <= 20 && day >= 1)
			return TAURUS;
		else if (day >= 21 && day <= 31)
			return GEMINI;
		break;
	case 6:
		if (day <= 20 && day >= 1)
			return GEMINI;
		else if (day >= 21 && day <= 30)
			return CANCER;
		break;
	case 7:
		if (day <= 22 && day >= 1)
			return CANCER;
		else if (day >= 23 && day <= 31)
			return LEO;
		break;
	case 8:
		if (day <= 22 && day >= 1)
			return LEO;
		else if (day >= 23 && day <= 31)
			return VIRGO;
		break;
	case 9:
		if (day <= 22 && day >= 1)
			return VIRGO;
		else if (day >= 23 && day <= 30)
			return LIBRA;
		break;
	case 10:
		if (day <= 22 && day >= 1)
			return LIBRA;
		else if (day >= 23 && day <= 31)
			return SCORPIO;
		break;
	case 11:
		if (day <= 21 && day >= 1)
			return SCORPIO;
		else if (day >= 22 && day <= 30)
			return SAGITTARIUS;
		break;
	case 12:
		if (day <= 21 && day >= 1)
			return SAGITTARIUS;
		else if (day >= 22 && day <= 31)
			return CAPRICORN;
		break;
	default:
		break;
	}
}



bool ZodiacReader::onCusp()
{
	int month = mDate.getMonth();
	int day = mDate.getDay();
	switch (month)
	{
	case 1:
		if (day == 19 || day == 20||day==18||day==21)
			return true;
		break;

	case 2:
		if (day == 19 || day == 18||day==17||day==20)
			return true;
		break;

	case 3:
		if (day == 20 || day == 21 || day == 19 || day == 22)
			return true;
		break;

	case 4:
		if (day == 19 || day == 20 || day == 18 || day == 21)
			return true;
		break;

	case 5:
		if (day == 20 || day == 21 || day == 19 || day == 22)
			return true;
		break;

	case 6:
		if (day == 20 || day == 21 || day == 19 || day == 22)
			return true;

		break;
	case 7:
		if (day == 22 || day == 23 || day == 24 || day == 21)
			return true;
		break;

	case 8:
		if (day == 22 || day == 23 || day == 24 || day == 21)
			return true;
		break;

	case 9:
		if (day == 22 || day == 23 || day == 24 || day == 21)
			return true;
		break;

	case 10:
		if (day == 22 || day == 23 || day == 24 || day == 21)
			return true;
		break;

	case 11:
		if (day == 22 || day == 21 || day == 20 || day == 23)
			return true;
		break;

	case 12:
		if (day == 22 || day == 21 || day == 20 || day == 23)
			return true;
		break;

	default:
		return false;
	}
	return false;
}

ZodiacReader::Sign ZodiacReader::cuspSign()
{
	int month = mDate.getMonth();
	int day = mDate.getDay();
	if (onCusp())
	{
		switch (month)
		{
		case 1:
			if (day == 19 || day == 18)
				return AQUARIUS;
			else
				return CAPRICORN;
			break;

		case 2:
			if (day == 18 || day == 17)
				return PISCES;
			else
				return AQUARIUS;
			break;

		case 3:
			if (day == 20 || day == 19)
				return ARIES;
			else
				return PISCES;
			break;

		case 4:
			if (day == 19 || day == 18)
				return TAURUS;
			else
				return ARIES;
			break;

		case 5:
			if (day == 20|| day == 19)
				return GEMINI;
			else
				return TAURUS;
			break;

		case 6:
			if (day == 20|| day == 19)
				return CANCER;
			else
				return GEMINI;
			break;

		case 7:
			if (day == 22|| day == 21)
				return LEO;
			else
				return CANCER;
			break;

		case 8:
			if (day == 22|| day == 21)
				return VIRGO;
			else
				return LEO;
			break;

		case 9:
			if (day == 22|| day == 21)
				return LIBRA;
			else
				return VIRGO;
			break;

		case 10:
			if (day == 22|| day == 21)
				return SCORPIO;
			else
				return LIBRA;
			break;

		case 11:
			if (day == 21|| day == 20)
				return SAGITTARIUS;
			else
				return SCORPIO;
			break;

		case 12:
			if (day == 21|| day == 20)
				return CAPRICORN;
			else
				return SAGITTARIUS;
			break;

		default:
			break;

		}
	}
	else
		return ARIES;
}

string ZodiacReader::stringifySign(Sign ZodiacReader)
{
	switch (ZodiacReader)
	{
	case AQUARIUS:
		return "Aquarius";
		break;

	case PISCES:
		return "Pisces";
		break;

	case ARIES:
		return "Aries";
		break;

	case TAURUS:
		return "Taurus";
		break;

	case GEMINI:
		return "Gemini";
		break;

	case CANCER:
		return "Cancer";
		break;

	case LEO:
		return "Leo";
		break;

	case VIRGO:
		return "Virgo";
		break;

	case LIBRA:
		return "Libra";
		break;

	case SCORPIO:
		return "Scorpio";
		break;

	case SAGITTARIUS:
		return "Sagittarius";
		break;

	case CAPRICORN:
		return "Capricorn";
		break;

	default:
		break;
	}
}

