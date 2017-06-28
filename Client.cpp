#include "stdafx.h"
#include "Client.h"



Client::~Client() = default;

BankCard Client::getCreditCard() const
{
	return bankCard;
}

long long Client::getNumberCreditCard() const
{
	return bankCard.getNumberCard();
}

std::string Client::getPassword() const
{
	return passwordToAccount;
}

void Client::setBankCard(const BankCard& newCreditCard, const std::string& generatedPasswordToAccount)
{
	bankCard = newCreditCard;
	passwordToAccount = generatedPasswordToAccount;
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