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