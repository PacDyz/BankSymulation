#pragma once
#include "Human.h"
#include <memory>
class Client
{
public:
	Client(const Human& human, const int& creditCardNumber) :human(human), creditCardNumber(creditCardNumber) {}
	int getPesel() const { return human.getPesel(); };
	~Client();
private:
	Human human;
	int creditCardNumber;
};

