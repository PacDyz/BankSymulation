#pragma once
#include "Human.h"
#include "CreditCard.h"
#include <memory>
class Client : public Human
{
public:
	Client(const Human&&);
	CreditCard getCreditCard() const;
	std::string getPassword() const;
	void setCreditCard(const CreditCard&, const std::string&);
	~Client();
private:
	CreditCard creditCard;
	std::string passwordToAccount;
};

std::ostream &operator<<(std::ostream& str, std::shared_ptr<Client>);


