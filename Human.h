#pragma once
#include <string>
class Human
{
public:
	Human(const std::string& name, const std::string& surname, const int& pesel) :name(name), surname(surname), pesel(pesel) {}
	int getPesel() const;
	~Human();
private:
	std::string name;
	std::string surname;
	int pesel;
};

