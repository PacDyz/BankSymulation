#pragma once
#include <string>
class CreditCard
{
public:
	CreditCard(const long long& numberCard,
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
	const long long numberCard;
	const std::string name;
	const std::string surname;
	const std::string typeOfCreditCard;
	const std::string expiryDate;
};

