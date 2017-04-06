#include "stdafx.h"
#include "Worker.h"


//Worker::Worker()
//{
//}


Worker::~Worker()
{
}

void Worker::changeSalary(int newSalary)
{
	salary = newSalary;
}
int Worker::getPesel() const
{
	return human->getPesel();
}