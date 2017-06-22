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
	Human(const std::string&,
		const std::string&,
		const int&);
	int getPesel() const;
	std::string getName() const;
	std::string getSurname() const;
	~Human();
private:
	Id id;
};

