#pragma once
#include "Money.h"
#include <memory>
class Euro : public Money
{
public:
	Euro(int value) :Money(value) {};
	Euro &operator+(Euro&&);
	Euro &operator-(Euro&&);
	bool operator==(const Euro&) const;
	~Euro();

};

