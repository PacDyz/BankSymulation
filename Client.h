#pragma once
#include "Human.h"
#include "CreditCard.h"
#include <memory>
class Client : public Human
{
public:
	Client(const Human&&);
	void setCreditCard(const CreditCard&, const std::string&);
	std::string getPassword() const;
	CreditCard getCreditCard() const;
	~Client();
private:
	CreditCard creditCard;
	std::string passwordToAccount;
};

std::ostream &operator<<(std::ostream& str, std::shared_ptr<Client>);


