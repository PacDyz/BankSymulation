#include "stdafx.h"
#include "Bank.h"

Bank::Bank(Euro&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice), countNumbersCards(0)
{
	newNumbersCards  = std::move(generator::generateNumberCard(1000000000000000));
}

Bank::~Bank(){}

void Bank::setCapital(const int& newCapital)
{
	capital = newCapital;
}
CreditCard Bank::createAccount(const Human& human, const std::string& password)
{
	long long numberCard = newNumbersCards.back();
	CreditCard creditCard(numberCard, human.getName(), human.getSurname(), "Visa", "12/22");
	auto account = std::make_unique<Account>(numberCard, 700, password );															
	listOfAccount.insert(std::make_pair(numberCard, std::move(account)));
	return creditCard;
}
void Bank::fillInAvailableNumberCard()
{
	countNumbersCards += 100;
	newNumbersCards = std::move(generator::generateNumberCard(1000000000000000 + countNumbersCards));
}
void Bank::addClient(const Human& human)
{
	std::string password = generator::generatePassword();
	CreditCard newCreditCard = createAccount(human, password);
	auto client = std::make_unique<Client>(std::move(human));
	client->setCreditCard(newCreditCard, password);							// change first argument...
	listOfClients.insert(std::make_pair(client->getPesel(), std::move(client)));
	if (newNumbersCards.empty())
	{
		fillInAvailableNumberCard();
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

void Bank::employWorker(const Human& human)
{
	auto worker = std::make_unique<Worker>(std::make_shared<Human>(human), 3500);
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