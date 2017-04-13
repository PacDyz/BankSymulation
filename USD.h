#pragma once
#include "Money.h"
class USD : public Money
{
public:
	USD();
	USD(const int&);
	USD(USD&& money);
	bool operator==(const USD&) const;
	USD &operator+=(USD&&);
	USD &operator-=(USD&&);
	USD &operator=(const int&);
	~USD();
};

