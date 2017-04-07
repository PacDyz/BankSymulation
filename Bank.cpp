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
	CreditCard creditCard(numberCards, human.getName(), human.getSurname(), "Visa", "12/22");
	auto client = std::make_unique<Client>(human);
	client->setCreditCard(creditCard);
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
void Bank::employWorker(const Client& client)
{
	auto worker = std::make_unique<Worker>(std::make_shared<Human>(client.getHuman()), 3500);
	listOfWorkers.insert(std::make_pair(worker->getPesel(), std::move(worker)));
}
void Bank::removeWorker(const int& pesel)
{
	listOfWorkers.erase(pesel);
}
void Bank::removeClient(const int& pesel)
{
	listOfClients.erase(pesel);
}