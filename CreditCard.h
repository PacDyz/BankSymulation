#pragma once
#include <string>
class CreditCard
{
public:
	CreditCard(const int& numberCard,
		const std::string& name,
		const std::string& surname,
		const std::string& typeOfCreditCard,
		const std::string& expiryDate) : numberCard(numberCard),
		name(name),
		surname(surname),
		typeOfCreditCard(typeOfCreditCard),
		expiryDate(expiryDate) {};
	~CreditCard();
private:
	int numberCard;
	std::string name;
	std::string surname;
	std::string typeOfCreditCard;
	std::string expiryDate;
};

