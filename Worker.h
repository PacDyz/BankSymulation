#pragma once
#include "Client.h"

class Worker
{
public:
	Worker(std::shared_ptr<Human>, const int&);
	void changeSalary(int salary);
	int getPesel() const;
	~Worker();
private:
	std::shared_ptr<Human> client;
	int salary;
};

