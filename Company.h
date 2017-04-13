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
	template<typename T>
	Company(T&&, const std::string&);
	template<>
	Company::Company(int&& capital, const std::string& mainOffice);
	bool findClient(const int&) const;
	int getNumberOfClients() const;
	std::string getMainOffice() const;
	void employWorker(const Human&);
	void removeClient(const int& pesel);
	void removeWorker(const int&);
	void setCapital(const int&);
	void displayAllClients() const;
	virtual void addClient(const Human&) = 0;
	virtual ~Company();
protected:
	int capital;
	std::string mainOffice;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

template<typename T>
Company::Company(T&& capital, const std::string& mainOffice) : capital(capital.getValue()*capital.getNominalValue()), mainOffice(mainOffice) {}

template<>
Company::Company(int&& capital, const std::string& mainOffice) : capital(std::move(capital)), mainOffice(mainOffice) {}