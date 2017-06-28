#pragma once
#include "bankCard.h"
class DebitCard : public BankCard
{
public:
	DebitCard(const long long&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&,
		const int&);
	~DebitCard();
private:
	int debit;
};

