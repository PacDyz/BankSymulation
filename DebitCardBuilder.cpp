#include "stdafx.h"
#include "DebitCardBuilder.h"



std::string DebitCardBuilder::getTypeOfBankCard() const
{
	return "debit card";
}
std::string DebitCardBuilder::getNameDistributorCard() const
{
	return "mastercard";
}
DebitCardBuilder::~DebitCardBuilder()
{
}
