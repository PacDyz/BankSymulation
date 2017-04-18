#include "stdafx.h"
#include "Client.h"


Client::Client(const Human&& human) : Human(std::move(human)), creditCard(0,"","","",""), passwordToAccount("") {}

Client::~Client() = default;

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
	str << "Client name: " << client->getName() << "\n";
	str << "Client surname: " << client->getSurname() << "\n";
	str << "Client pesel: " << client->getPesel() << "\n";
	if (client->getCreditCard().getNumberCard() != 0)
		str << "Client credit card: " << client->getCreditCard().getNumberCard() << "\n";
	else
		str << "Client credit card: Client doesn't have credit card" << "\n";
	return str;
}


long long Client::getNumberCreditCard() const
{
	return creditCard.getNumberCard();
}