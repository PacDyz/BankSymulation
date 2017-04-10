#pragma once
#include <string>
#include <memory>
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
	std::string getName() const;
	std::string getSurname() const;
	int getPesel() const;
	~Human();
private:
	Id id;
};

