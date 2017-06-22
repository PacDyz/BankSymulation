#include "stdafx.h"
#include "Euro.h"
#include <memory>

Euro::Euro() : Money(1.0) {}

Euro::Euro(Euro&& euro) : Money(std::move(euro)) {}

Euro::Euro(const int& value) : Money(value) {}

bool Euro::operator==(const Euro& euro) const
{
	return value == euro.value;
}

Euro &Euro::operator+=( const Euro&& euro)
{
	value += euro.value;
	return *this;
}

Euro &Euro::operator-=(const Euro&& euro)
{
	value -= euro.value;
	return *this;
}

Euro &Euro::operator=(const int& newEuro)
{
	value = newEuro;
	return *this;
}

Euro::~Euro() = default;