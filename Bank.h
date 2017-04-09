#pragma once
#include "Company.h"
#include "CreditCard.h"
#include "Account.h"
class Bank : public Company
{
public:
	Bank(Euro&&, const std::string&);
	void setCapital(const int& );
	void addClient(const Human&);
	void employWorker(const Client&);
	void removeWorker(const int&);
	void removeClient(const int& pesel);
	bool findClient(const int&) const;
	std::string getMainOffice() const;
	int getNumberOfClients() const;
	~Bank();
private:
	std::vector<long long> newNumbersCards;
	long long countNumbersCards;
};

