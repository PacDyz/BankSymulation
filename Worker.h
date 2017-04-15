#pragma once
#include "Client.h"

class Worker
{
public:
	Worker(std::shared_ptr<Human>, const int&);
	int getPesel() const;
	void changeSalary(const int& salary);
	~Worker();
private:
	std::shared_ptr<Human> human;
	int salary;
};

