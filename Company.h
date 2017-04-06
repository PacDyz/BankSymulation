#pragma once
#include <memory>
#include <map>
#include "Client.h"
class Company
{
public:
	Company(const int& capital, const std::string& mainOffice) :capital(capital), mainOffice(mainOffice) {}
	virtual void setCapital(const int&)=0;
	virtual void addClient(const Human&)=0;
	virtual bool findClient(const int&)=0;
	virtual std::string getMainOffice()=0;
	virtual int getNumberOfClients()=0;
	virtual ~Company();
protected:
	int capital;
	std::string mainOffice;
	std::map<int, std::unique_ptr<Client>> listOfClients;
};

