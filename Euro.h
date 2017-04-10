#pragma once
#include "Money.h"

class Euro : public Money
{
public:
	Euro(const int&);
	Euro(Euro&& money) : Money(std::move(money)) {};
	Euro &operator+(Euro&&);
	Euro &operator-(Euro&&);
	bool operator==(const Euro&) const;
	Euro &operator=(const int&);
	~Euro();

};

