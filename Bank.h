#pragma once
#include "Account.h"
#include "Company.h"

class Bank : public Company
{
public:
	Bank(Euro&&, const std::string&);
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

