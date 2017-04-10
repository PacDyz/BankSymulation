#pragma once
#include <string>
class CreditCard
{
public:
	CreditCard(const long long&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&);
	CreditCard &operator=(const CreditCard& cr) { return CreditCard(cr.numberCard, cr.name, cr.surname, cr.typeOfCreditCard, cr.expiryDate); }
	~CreditCard();
private:
	const long long numberCard;
	const std::string name;
	const std::string surname;
	const std::string typeOfCreditCard;
	const std::string expiryDate;
};

