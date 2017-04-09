#pragma once
#include "Human.h"
#include "CreditCard.h"
#include <memory>
class Client
{
public:
	Client(const Human& human) :human(human), creditCard(nullptr), passwordToAccount("") {}
	void setCreditCard(const CreditCard&, const std::string&);
	Human getHuman() const { return human; };
	int getPesel() const { return human.getPesel(); };
	std::string getPassword() const;
	~Client();
private:
	Human human;
	std::unique_ptr<CreditCard> creditCard;
	std::string passwordToAccount;
};

