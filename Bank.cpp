#include "stdafx.h"
#include "Bank.h"

Bank::Bank(Euro&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice), countNumbersCards(0)
{
	newNumbersCards  = std::move(generator::generateNumberCard(1000000000000000));
}


Bank::~Bank()
{
}
void Bank::setCapital(const int& newCapital)
{
	capital = newCapital;
}

void Bank::addClient(const Human& human)
{
	long long numberCard = newNumbersCards.back();
	CreditCard creditCard(numberCard, human.getName(), human.getSurname(), "Visa", "12/22");
	std::string password = generator::generatePassword();													// extract to another method
	Account account{ numberCard, 700, password };															// change second argument, must set some money											
	auto client = std::make_unique<Client>(human);
	client->setCreditCard(creditCard, password);
	listOfClients.insert(std::make_pair(client->getPesel(), std::move(client)));
	if (newNumbersCards.empty())
	{
		countNumbersCards += 100;
		newNumbersCards = std::move(generator::generateNumberCard(1000000000000000 + countNumbersCards));  
	}
}
bool Bank::findClient(const int& pesel) const
{
	auto itr = listOfClients.find(pesel);
	return itr != std::end(listOfClients);
}

std::string Bank::getMainOffice() const
{
	return mainOffice;
}
int Bank::getNumberOfClients() const
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