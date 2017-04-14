#include "stdafx.h"
#include "USD.h"
#include <memory>

USD::USD() :Money(0.9) {}

USD::USD(const int& value ): Money(value){}

USD::USD(const USD&& usd) : Money(std::move(usd)) {}

USD::~USD() = default;

USD &USD::operator+=(const USD&& usd)
{
	value += usd.value;
	return *this;
}

USD &USD::operator-=(const USD&& usd)
{
	value -= usd.value;
	return *this;
}

bool USD::operator==(const USD& usd) const
{
	return value == usd.value;
}

USD &USD::operator=(const int& newUSD)
{
	value = newUSD;
	return *this;
}
