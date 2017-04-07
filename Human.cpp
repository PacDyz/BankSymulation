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
	return id.pesel;
}
std::string Human::getName() const
{
	return id.name;
}
std::string Human::getSurname() const
{
	return id.surname;
}

