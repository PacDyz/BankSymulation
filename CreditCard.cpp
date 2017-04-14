#include "stdafx.h"
#include "CreditCard.h"


CreditCard::CreditCard(const long long& numberCard,
	const std::string& name,
	const std::string& surname,
	const std::string& typeOfCreditCard,
	const std::string& expiryDate) : numberCard(numberCard),
	name( name ),
	surname( surname ),
	typeOfCreditCard( typeOfCreditCard ),
	expiryDate( expiryDate ) {}

CreditCard::~CreditCard() = default;

void CreditCard::operator=(const CreditCard& creditCard) {
	numberCard = creditCard.numberCard;  
	name = creditCard.name;
	surname = creditCard.surname;
	typeOfCreditCard = creditCard.typeOfCreditCard;
	expiryDate = creditCard.expiryDate;
}

long long CreditCard::getNumberCard() const
{
	return numberCard;
}
std::string CreditCard::getName() const
{
	return name;
}
std::string CreditCard::getSurname() const
{
	return surname;
}
std::string CreditCard::getTypeOfCreditCard() const
{
	return typeOfCreditCard;
}
std::string CreditCard::getExpiryDate() const
{
	return expiryDate;
}

std::ostream &operator<<(std::ostream& str, const CreditCard& creditCard)
{
	str << "Number card: " << creditCard.getNumberCard() << std::endl;
	str << "Name owner: " << creditCard.getName() << std::endl;
	str << "Surname owner: " << creditCard.getSurname() << std::endl;
	str << "Type of card: " << creditCard.getTypeOfCreditCard() << std::endl;
	str << "Expiry date: " << creditCard.getExpiryDate() << std::endl;
	return str;
}
