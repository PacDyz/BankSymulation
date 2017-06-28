#include "stdafx.h"
#include "DebitCard.h"


DebitCard::DebitCard(const long long& numberCard,
	const std::string& name,
	const std::string& surname,
	const std::string& typeOfCreditCard,
	const std::string& expiryDate,
	const int& debit) : BankCard(numberCard,name,surname,typeOfCreditCard,expiryDate), debit(debit) {}


DebitCard::~DebitCard()
{
}
