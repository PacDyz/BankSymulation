#include "stdafx.h"
#include "Euro.h"


Euro::Euro(const int& value) : Money(value) {};


Euro::~Euro()
{
}

Euro &Euro::operator+(Euro&& euro)
{
	value += euro.value;
	return *this;
}

Euro &Euro::operator-(Euro&& euro)
{
	value -= euro.value;
	return *this;
}

bool Euro::operator==(const Euro& euro) const
{
	return value == euro.value;
}

Euro &Euro::operator=(const int& newMoney)
{
	value = newMoney;
	return *this;
}
