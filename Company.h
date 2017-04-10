#pragma once
#include <memory>
#include <map>
#include "Euro.h"
#include "Worker.h"
#include <vector>
namespace generator
{
	std::vector<long long> generateNumberCard(const long long&);
	std::string generatePassword();
}
class Company
{
public:
	Company(Euro&&, const std::string&);
	virtual void addClient(const Human&) = 0;
	virtual void employWorker(const Human&) = 0;
	virtual bool findClient(const int&) const = 0;
	virtual std::string getMainOffice() const = 0;
	virtual int getNumberOfClients() const = 0;
	virtual void removeClient(const int& pesel) = 0;
	virtual void removeWorker(const int&) = 0;
	virtual void setCapital(const int&) = 0;
	virtual ~Company();
protected:
	Euro capital;
	std::string mainOffice;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

