#pragma once
#include <memory>
#include <map>
#include "Euro.h"
#include "Worker.h"
#include <vector>
namespace generator
{
	std::vector<long long> generateNumberCard(const long long&);                    // change this function, create class GeneratorNumberCard, and safe state, card in each bank schould have other number.
	std::string generatePassword();
}
class Company
{
public:
	template<typename T>
	Company(const T&&, const std::string&);
	template<>
	Company(const int&& capital, const std::string& mainOffice);
	void setCompany(const int&&,
					const std::string&&,
					std::map<int, std::shared_ptr<Client>>&&,
					std::map<int, std::unique_ptr<Worker>>&&);
	bool findClient(const int&) const;
	int getNumberOfClients() const;
	std::string getMainOffice() const;
	void employWorker(const Human&);
	void removeClient(const int&);
	void removeWorker(const int&);
	void setCapital(const int&);
	void displayAllClients() const;
	void moveClients(std::map<int, std::shared_ptr<Client>>&&);
	void moveWorkers(std::map<int, std::unique_ptr<Worker>>&&);
	virtual void addClient(const Human&) = 0;
	virtual ~Company();
protected:
	int capital;
	std::string mainOffice;
	std::string office;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

template<typename T>
Company::Company(const T&& capital, const std::string& mainOffice) : capital(capital.getValue()*capital.getNominalValue()), mainOffice(mainOffice) {}

template<>
Company::Company(const int&& capital, const std::string& mainOffice) : capital(std::move(capital)), mainOffice(mainOffice) {}