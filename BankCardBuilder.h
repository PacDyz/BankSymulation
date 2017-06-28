#pragma once
#include "BankCard.h"
#include <memory>
class BankCardBuilder
{
public:
	BankCardBuilder();
	std::string setExpiryDate();
	virtual std::string getTypeOfBankCard() const = 0;
	virtual std::string getNameDistributorCard() const = 0;
	virtual ~BankCardBuilder();
};

