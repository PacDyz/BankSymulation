#include "stdafx.h"
#include "Money.h"
#include <memory>

Money::Money(const Money&&) :value{ std::move(value) } {}

Money::Money(const int& value, const double& nominalValue) : value{ value },
															nominalValue{ nominalValue } {}

Money::Money(const double& nominalValue) : nominalValue{ nominalValue }, value{ 0 } {}

double Money::getNominalValue() const
{
	return nominalValue;
}

int Money::getValue() const
{
	return value;
}

Money::~Money() = default;
