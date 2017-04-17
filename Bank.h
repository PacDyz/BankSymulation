#pragma once
#include "Account.h"
#include "Company.h"

class Bank : public Company
{
public:
	template<typename T>
	Bank(const T&&, const std::string&);
	template<>
	Bank(const int&&, const std::string&);
	void addClient(const Human&);
	void addMoneyToAccount(const int&&, const long long&);
	auto findAccount(const long long& numberCard) const;
	void moveAccount(std::map<long long, std::unique_ptr<Account>>&&);
	void displayStateAccount(const long long&);
	void setBank(Bank&&);
	void checkNumberAvailableCard();
	CreditCard createAccount(const Human&, const std::string&);
	void fillInAvailableNumberCard();
	~Bank();
private:
	std::map<long long, std::unique_ptr<Account>> listOfAccount;
	std::vector<long long> newNumbersCards;
};

template<typename T>
Bank::Bank(const T&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice){}

template<>
Bank::Bank(const int&& capital, const std::string& mainOffice) : Company(std::move(capital), mainOffice){}

