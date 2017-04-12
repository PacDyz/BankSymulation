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
	void operator=(const CreditCard& );
	long long getNumberCard() const;
	std::string getName() const;
	std::string getSurname() const;
	std::string getTypeOfCreditCard() const;
	std::string getExpiryDate() const;
	~CreditCard();
private:
	 long long numberCard;
	 std::string name;
	 std::string surname;
	 std::string typeOfCreditCard;
	 std::string expiryDate;
};

std::ostream &operator<<(std::ostream& str, const CreditCard&);
