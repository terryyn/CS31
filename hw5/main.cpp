#include <iostream>
#include <string>
#include <cassert>
#include "Date.h"
#include "ZodiacReader.h"

int main()
{
	Date jan1(1, 1);
	ZodiacReader reader(jan1);
	assert(reader.stringifySign(reader.checkSign()) == "Capricorn");
	assert(reader.checkSign() == ZodiacReader::CAPRICORN);
	assert(!reader.onCusp());

	Date jan20(1, 20);
	ZodiacReader reader1(jan20);
	assert(reader1.stringifySign(reader1.checkSign()) == "Aquarius");
	assert(reader1.checkSign() == ZodiacReader::AQUARIUS);
	assert(reader1.onCusp());
	assert(reader1.stringifySign(reader1.cuspSign()) == "Capricorn");
	assert(reader1.cuspSign() == ZodiacReader::CAPRICORN);


	cout << "all passed!" << endl;



	return 0;

	cout << "All tests are succeeded" << endl;
	return 0;
}
