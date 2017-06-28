#pragma once
#include "BankCardBuilder.h"
class CreditCardBuilder : public BankCardBuilder
{
public:
	std::string getTypeOfBankCard() const override;
	std::string getNameDistributorCard() const override;
	~CreditCardBuilder();
};

