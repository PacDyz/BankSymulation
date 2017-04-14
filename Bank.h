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
	void moveAccount(std::map<long long, std::unique_ptr<Account>>&&);
	void setBank(Bank&&);
	void addClient(const Human&);
	void checkNumberAvailableCard();
	CreditCard createAccount(const Human&, const std::string&);
	void fillInAvailableNumberCard();
	~Bank();
private:
	long long countNumbersCards;
	std::map<long long, std::unique_ptr<Account>> listOfAccount;
	std::vector<long long> newNumbersCards;
};

template<typename T>
Bank::Bank(const T&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice), countNumbersCards(0)
{
	newNumbersCards = std::move(generator::generateNumberCard(1000000000000000));
}

template<>
Bank::Bank(const int&& capital, const std::string& mainOffice) : Company(std::move(capital), mainOffice), countNumbersCards(0)
{
	newNumbersCards = std::move(generator::generateNumberCard(1000000000000000));
}

