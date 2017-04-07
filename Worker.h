#pragma once
#include "Client.h"
class Worker
{
public:
	Worker(std::shared_ptr<Human> human, const int& salary) :human(human), salary(salary){}
	void changeSalary(int salary);
	int getPesel() const;
	~Worker();
private:
	std::shared_ptr<Human> human;
	int salary;
};

