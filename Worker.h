#pragma once
#include "Client.h"
#include "Company.h"
class Worker
{
public:
	Worker(const Client& client, std::unique_ptr<Company> company, const int& salary) :client(std::make_unique<Client>(client)), salary(salary), company(std::move(company)) {}
	void changeSalary(int salary);
	~Worker();
private:
	std::unique_ptr<Client> client;
	std::unique_ptr<Company> company;
	int salary;
};

