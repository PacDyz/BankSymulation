#pragma once
#include <string>
struct Id 
{
	const std::string name;
	const std::string surname;
	const int pesel;
};
class Human
{
public:
	Human(const std::string& name,
		const std::string& surname,
		const int& pesel) : id({ name,surname,pesel }) {}
	std::string getName() const;
	std::string getSurname() const;
	int getPesel() const;
	~Human();
private:
	Id id;
};

