#pragma once
#include "Human.h"
#include <memory>
class Client
{
public:
	Client(const Human& human, const int& creditCardNumber) :human(std::make_unique<Human>(human)), creditCardNumber(creditCardNumber) {}
	int getPesel() const { return human->getPesel(); };
	~Client();
private:
	std::unique_ptr<Human> human;
	int creditCardNumber;
};

