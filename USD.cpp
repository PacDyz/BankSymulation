#include "stdafx.h"
#include "USD.h"

USD::USD() :Money(0.9) {}

USD::USD(const int& value ): Money(value){}

USD::~USD(){}

USD &USD::operator+=(USD&& euro)
{
	value += euro.value;
	return *this;
}

USD &USD::operator-=(USD&& euro)
{
	value -= euro.value;
	return *this;
}

bool USD::operator==(const USD& euro) const
{
	return value == euro.value;
}

USD &USD::operator=(const int& newMoney)
{
	value = newMoney;
	return *this;
}
