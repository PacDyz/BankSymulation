#pragma once
#include "Money.h"
class USD : public Money
{
public:
	USD();
	USD(const int&);
	USD(USD&& money) : Money(std::move(money)) {};
	USD &operator+=(USD&&);
	USD &operator-=(USD&&);
	bool operator==(const USD&) const;
	USD &operator=(const int&);
	~USD();
};

