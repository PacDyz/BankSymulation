#include "stdafx.h"
#include "Bank.h"

/*Bank::Bank()
{
}*/


Bank::~Bank()
{
}
void Bank::setCapital(const int& newCapital)
{
	capital = newCapital;
}

void Bank::addClient(const Human& human)
{
	std::unique_ptr<Client> client = std::make_unique<Client>(human, 7854684);
	listOfClients.insert(std::make_pair(client->getPesel(), std::move(client)));
}
bool Bank::findClient(const int& pesel)
{
	auto itr = listOfClients.find(pesel);
	return itr != std::end(listOfClients);
}

std::string Bank::getMainOffice()
{
	return mainOffice;
}
int Bank::getNumberOfClients()
{
	return listOfClients.size();
}