#pragma once
#include "Account.h"
#include "Company.h"

class Bank : public Company
{
public:
	Bank(Euro&&, const std::string&);
	void addClient(const Human&);
	void check();
	CreditCard createAccount(const Human&, const std::string&);
	void employWorker(const Human&);
	std::string getMainOffice() const;
	int getNumberOfClients() const;
	void fillInAvailableNumberCard();
	bool findClient(const int&) const;
	void removeClient(const int& pesel);
	void removeWorker(const int&);
	void setCapital(const int&);
	~Bank();
private:
	long long countNumbersCards;
	std::map<long long, std::unique_ptr<Account>> listOfAccount;
	std::vector<long long> newNumbersCards;
};

