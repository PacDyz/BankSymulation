#pragma once
#include <string>
class BankCard
{
public:
	//CreditCard() :numberCard(0), name(""), surname(""), typeOfCreditCard(""), expiryDate("") {}
	BankCard(const long long&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&,
		const std::string&);
	long long getNumberCard() const;
	std::string getExpiryDate() const;
	std::string getName() const;
	std::string getNameCard() const;
	std::string getSurname() const;
	std::string getTypeOfBankCard() const;
	void operator=(const BankCard&);
	~BankCard();
private:
	 long long numberCard;
	 std::string expiryDate;
	 std::string name;
	 std::string surname;
	 std::string typeOfBankCard;
	 std::string nameCard;
};

std::ostream &operator<<(std::ostream& str, const BankCard&);
