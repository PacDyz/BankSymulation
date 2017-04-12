#pragma once
#include "Money.h"

class Euro : public Money
{
public:
	Euro();
	Euro(const int&);
	Euro(Euro&& money) : Money(std::move(money)) {};
	bool operator==(const Euro&) const;
	Euro &operator+=(Euro&&);
	Euro &operator-=(Euro&&);
	Euro &operator=(const int&);
	~Euro();

};

