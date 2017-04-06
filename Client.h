#pragma once
#include "Human.h"
#include "CreditCard.h"
#include <memory>
class Client
{
public:
	Client(const Human& human) :human(human), creditCard(nullptr) {}
	void setCreditCard(const CreditCard&);
	Human getHuman() const { return human; };
	int getPesel() const { return human.getPesel(); };
	~Client();
private:
	Human human;
	std::unique_ptr<CreditCard> creditCard;
};

