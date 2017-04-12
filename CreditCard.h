#pragma once
#include <string>
class CreditCard
{
public:
	//CreditCard() :numberCard(0), name(""), surname(""), typeOfCreditCard(""), expiryDate("") {}
	CreditCard(const long long&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&);
	void operator=(const CreditCard& cr) {
		numberCard = cr.numberCard;  name = cr.name; surname = cr.surname; typeOfCreditCard = cr.typeOfCreditCard; expiryDate = cr.expiryDate; }
	~CreditCard();
private:
	 long long numberCard;
	 std::string name;
	 std::string surname;
	 std::string typeOfCreditCard;
	 std::string expiryDate;
};

