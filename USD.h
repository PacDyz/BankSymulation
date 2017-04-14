#pragma once
#include "Money.h"
class USD : public Money
{
public:
	USD();
	USD(const int&);
	USD(const USD&&);
	bool operator==(const USD&) const;
	USD &operator+=(const USD&&);
	USD &operator-=(const USD&&);
	USD &operator=(const int&);
	~USD();
};

