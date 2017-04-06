#pragma once
#include <map>
#include "Company.h"
class Bank : public Company
{
public:
	Bank(const int& capital, const std::string& mainOffice) :Company(capital, mainOffice) {}
	void setCapital(const int& );
	void addClient(const Human&);
	bool findClient(const int&);
	std::string getMainOffice();
	int getNumberOfClients();
	~Bank();
};

