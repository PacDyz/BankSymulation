#pragma once
#include <memory>
#include <map>
#include "Euro.h"
#include "Worker.h"
#include <vector>

namespace generator
{
	static long long counterNumbersCards = 1000000000000000;
	static int getRandomNumber(const int& begin, const int& end);
	std::vector<long long> generateNumberCard();
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
	std::shared_ptr<Client> findClient(const int&) const;
	int getNumberOfClients() const;
	std::string getMainOffice() const;
	void employWorker(std::shared_ptr<Human>);
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
	std::vector<std::string> office;
	std::map<int, std::shared_ptr<Client>> listOfClients;
	std::map<int, std::unique_ptr<Worker>> listOfWorkers;
};

template<typename T>
Company::Company(const T&& capital, const std::string& mainOffice) : capital(capital.getValue()*capital.getNominalValue()), mainOffice(mainOffice) {}

template<>
Company::Company(const int&& capital, const std::string& mainOffice) : capital(std::move(capital)), mainOffice(mainOffice) {}