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
	long long getNumberCard() const;
	std::string getExpiryDate() const;
	std::string getName() const;
	std::string getSurname() const;
	std::string getTypeOfCreditCard() const;
	void operator=(const CreditCard&);
	~CreditCard();
private:
	 long long numberCard;
	 std::string expiryDate;
	 std::string name;
	 std::string surname;
	 std::string typeOfCreditCard;
};

std::ostream &operator<<(std::ostream& str, const CreditCard&);
