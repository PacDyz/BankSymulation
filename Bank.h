#pragma once
#include <map>
#include "Human.h"
#include "Client.h"
class Bank
{
public:
	Bank(const int& capital, const std::string& mainOffice) :capital(capital), mainOffice(mainOffice)  {}
	void setCapital(const int& );
	void addClient(const Human&);
	bool findClient(const int&);
	std::string getMainOffice();
	int getNumberOfClients();
	~Bank();
private:
	int capital;
	std::string mainOffice;
	std::map<int, std::unique_ptr<Client>> listOfClients;
};

