#include "stdafx.h"
#include "Client.h"


/*Client::Client()
{
}
*/

Client::~Client()
{
}

void Client::setCreditCard(const CreditCard& newCreditCard)
{
	creditCard.reset(new CreditCard(newCreditCard));
}
