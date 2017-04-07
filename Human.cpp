#include "stdafx.h"
#include "Human.h"


//Client::Client()
//{
//}


Human::~Human()
{
}
int Human::getPesel() const
{
	return pesel;
}
std::string Human::getName() const
{
	return name;
}
std::string Human::getSurname() const
{
	return surname;
}

