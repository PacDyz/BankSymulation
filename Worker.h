#pragma once
#include "Client.h"
class Worker
{
public:
	Worker(const Client& client, const int& salary) :client(std::make_shared<Client>(client)), salary(salary){}
	void changeSalary(int salary);
	int getPesel() const;
	~Worker();
private:
	std::shared_ptr<Client> client;
	int salary;
};

