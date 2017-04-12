#include "stdafx.h"
#include "Bank.h"
#include <future>
#include <iostream>
#include <thread>
//std::condition_variable cond;
//std::mutex mu;
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
void Bank::check() {
	if (newNumbersCards.empty())
	{
		//t1 = std::thread(&Bank::fillInAvailableNumberCard, this);
		//auto fut = std::async(std::launch::async, &Bank::fillInAvailableNumberCard, this);
		fillInAvailableNumberCard();
	}
}
void Bank::addClient(const Human& human)
{
	//std::thread t1(&Bank::check, this);
	check();
	//std::promise<std::string> p;
	//auto password = p.get_future();
	std::string password = generator::generatePassword();
	//auto f = std::async(std::launch::async, &generator::generatePassword);
	//std::thread t5(generator::generatePassword, std::move(f));
	//t1.join();
	//t5.join();
	CreditCard newCreditCard = createAccount(human, password);
	//auto fu = std::async(std::launch::async, &Bank::createAccount, this,  human, password);
	//CreditCard newCreditCard;
	//std::thread t3(&Bank::createAccount, this, human, password, std::ref(newCreditCard));
	//t3.join();
	auto client = std::make_unique<Client>(std::move(human));
	//CreditCard newCreditCard = fu.get();
	//std::thread t2(&Client::setCreditCard, *client, newCreditCard, password);						// change first argument...
	//t2.join();
	client->setCreditCard(newCreditCard, password);
	listOfClients.insert(std::make_pair(client->getPesel(), std::move(client)));
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