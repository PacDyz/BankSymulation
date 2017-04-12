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
	bool findClient(const int&) const;
	int getNumberOfClients() const;
	std::string getMainOffice() const;
	void employWorker(const Human&);
	void removeClient(const int& pesel);
	void removeWorker(const int&);
	void setCapital(const int&);
	virtual void addClient(const Human&) = 0;
	virtual ~Company();
protected:
	Euro capital;
	std::string mainOffice;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

