#include "stdafx.h"
#include "CreditCardBuilder.h"


std::string CreditCardBuilder::getTypeOfBankCard() const 
{
	return "credit card";
}
std::string CreditCardBuilder::getNameDistributorCard() const 
{
	return "visa";
}
CreditCardBuilder::~CreditCardBuilder()
{
}
