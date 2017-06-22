#include "stdafx.h"
#include "Human.h"


Human::Human(const std::string& name,
	const std::string& surname,
	const int& pesel) : id({ name,surname,pesel }) {}

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

Human::~Human() = default;
//Human::Human(std::unique_ptr<Human> human) :Human(human->getName(), human->getSurname(), human->getPesel()) {}

