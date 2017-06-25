#include "stdafx.h"
#include "Worker.h"

Worker::Worker(std::shared_ptr<Human> human, const int& salary) : human{ human }, salary{ salary } {}

int Worker::getPesel() const
{
	return human->getPesel();
}

void Worker::changeSalary(const int& newSalary)
{
	salary = newSalary;
}

Worker::~Worker() = default;