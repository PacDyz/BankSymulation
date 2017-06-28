#pragma once
#include "BankCardBuilder.h"
class DebitCardBuilder : public BankCardBuilder
{
public:
	std::string getTypeOfBankCard() const override;
	std::string getNameDistributorCard() const override;
	~DebitCardBuilder();
};

