#include "stdafx.h"
#include "Worker.h"

Worker::Worker( std::shared_ptr<Human> client, const int& salary) : client(client), salary(salary){}


Worker::~Worker() = default;

void Worker::changeSalary(int newSalary)
{
	salary = newSalary;
}

int Worker::getPesel() const
{
	return client->getPesel();
}