#include "stdafx.h"
#include "Worker.h"

Worker::Worker( std::shared_ptr<Human> human, const int& salary) : human(human), salary(salary){}


Worker::~Worker() = default;

void Worker::changeSalary(const int& newSalary)
{
	salary = newSalary;
}

int Worker::getPesel() const
{
	return human->getPesel();
}