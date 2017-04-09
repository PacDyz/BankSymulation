#include "stdafx.h"
#include "Client.h"


/*Client::Client()
{
}
*/

Client::~Client()
{
}

void Client::setCreditCard(const CreditCard& newCreditCard, const std::string& generatedPasswordToAccount)
{
	creditCard.reset(new CreditCard(newCreditCard));
	passwordToAccount = generatedPasswordToAccount;
}
std::string Client::getPassword() const
{
	return passwordToAccount;
}