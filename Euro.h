#pragma once
#include "Money.h"

class Euro : public Money
{
public:
	Euro();
	Euro(const int&);
	Euro(Euro&&);
	bool operator==(const Euro&) const;
	Euro &operator+=(const Euro&&);
	Euro &operator-=(const Euro&&);
	Euro &operator=(const int&);
	~Euro();

};

