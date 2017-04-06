#pragma once
#include <memory>
#include <map>
#include "Worker.h"

class Company
{
public:
	Company(const int& capital, const std::string& mainOffice) :capital(capital), mainOffice(mainOffice) {}
	virtual void setCapital(const int&)=0;
	virtual void addClient(const Human&)=0;
	virtual void employWorker(const Client&)=0;
	virtual bool findClient(const int&)=0;
	virtual void removeWorker(const int&)=0;
	virtual void removeClient(const int& pesel)=0;
	virtual std::string getMainOffice()=0;
	virtual int getNumberOfClients()=0;
	virtual ~Company();
protected:
	int capital;
	std::string mainOffice;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

