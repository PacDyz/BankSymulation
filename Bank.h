#pragma once
#include <map>
#include "Company.h"
#include  "CreditCard.h"
class Bank : public Company
{
public:
	Bank(const int& capital, const std::string& mainOffice) :Company(capital, mainOffice), numberCards(0) {}
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
	int numberCards;
};

