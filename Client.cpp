#include "stdafx.h"
#include "Client.h"


Client::Client(const Human&& human) : Human(std::move(human)), creditCard(0,"","","",""), passwordToAccount("") {}

Client::~Client() {}

void Client::setCreditCard(const CreditCard& newCreditCard, const std::string& generatedPasswordToAccount)
{
	creditCard = newCreditCard;
	passwordToAccount = generatedPasswordToAccount;
}

std::string Client::getPassword() const
{
	return passwordToAccount;
}

CreditCard Client::getCreditCard() const
{
	return creditCard;
}

std::ostream &operator<<(std::ostream& str, std::shared_ptr<Client> client)
{
	str << "Client name: " << client->getName() << std::endl;
	str << "Client surname: " << client->getSurname() << std::endl;
	str << "Client pesel: " << client->getPesel() << std::endl;
	if (client->getCreditCard().getNumberCard() != 0)
		str << "Client credit card: " << client->getCreditCard().getNumberCard() << std::endl;
	else
		str << "Client credit card: Client doesn't have credit card" << std::endl;
	return str;
}