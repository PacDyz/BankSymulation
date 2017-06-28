#include "stdafx.h"
#include "BankCard.h"


BankCard::BankCard(const long long& numberCard,
	const std::string& name,
	const std::string& surname,
	const std::string& typeOfCreditCard,
	const std::string& expiryDate,
	const std::string& nameCard) : numberCard(numberCard),
	name( name ),
	surname( surname ),
	typeOfBankCard( typeOfCreditCard ),
	expiryDate( expiryDate ),
	nameCard(nameCard){}

void BankCard::operator=(const BankCard& bankCard) {
	numberCard = bankCard.numberCard;  
	name = bankCard.name;
	surname = bankCard.surname;
	typeOfBankCard = bankCard.typeOfBankCard;
	expiryDate = bankCard.expiryDate;
}

long long BankCard::getNumberCard() const
{
	return numberCard;
}
std::string BankCard::getName() const
{
	return name;
}
std::string BankCard::getNameCard() const
{
	return nameCard;
}
std::string BankCard::getSurname() const
{
	return surname;
}
std::string BankCard::getTypeOfBankCard() const
{
	return typeOfBankCard;
}
std::string BankCard::getExpiryDate() const
{
	return expiryDate;
}

std::ostream &operator<<(std::ostream& str, const BankCard& bankCard)
{
	str << "Number card: " << bankCard.getNumberCard() << std::endl;
	str << "Name owner: " << bankCard.getName() << std::endl;
	str << "Surname owner: " << bankCard.getSurname() << std::endl;
	str << "Type of card: " << bankCard.getTypeOfBankCard() << std::endl;
	str << "Expiry date: " << bankCard.getExpiryDate() << std::endl;
	str << "Name Card" << bankCard.getNameCard() << std::endl;
	return str;
}

BankCard::~BankCard() = default;