#include "stdafx.h"
#include "Bank.h"
#include <future>
#include <iostream>
#include <thread>
//std::condition_variable cond;
//std::mutex mu;


Bank::~Bank() = default;

CreditCard Bank::createAccount(const Human& human, const std::string& password)
{
	long long numberCard = newNumbersCards.back();
	newNumbersCards.pop_back();
	CreditCard creditCard(numberCard, human.getName(), human.getSurname(), "Visa", "12/22");
	auto account = std::make_unique<Account>( numberCard, 700, password );
	listOfAccount.insert(std::make_pair(numberCard, std::move(account)));
	return creditCard;
}
void Bank::fillInAvailableNumberCard()
{
	newNumbersCards = std::move(generator::generateNumberCard());
}
void Bank::checkNumberAvailableCard() {
	if (newNumbersCards.empty())
	{
		//t1 = std::thread(&Bank::fillInAvailableNumberCard, this);
		//auto fut = std::async(std::launch::async, &Bank::fillInAvailableNumberCard, this);
		fillInAvailableNumberCard();
	}
}
void Bank::addClient(const Human& human)
{
	//std::thread t1(&Bank::checkNumberAvailableCard, this);
	checkNumberAvailableCard();
	//std::promise<std::string> p;
	//auto password = p.get_future();
	std::string password = generator::generatePassword();
	//auto f = std::async(std::launch::async, &generator::generatePassword);
	//std::thread t5(generator::generatePassword, std::move(f));
	//t1.join();
	//t5.join();
	CreditCard newCreditCard = createAccount(human, password);
	//std::string password = f.get();
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
void Bank::moveAccount(std::map<long long, std::unique_ptr<Account>>&& listOfAccount)
{
	listOfAccount.insert(std::make_move_iterator(listOfAccount.begin()), std::make_move_iterator(listOfAccount.end())); // c++17 this->listOfAccount.merge(listOfAccount);
	listOfAccount.clear();
}
void Bank::setBank(Bank&& bank)
{
	std::thread t1(&Bank::moveAccount, this, std::move(bank.listOfAccount));
	std::thread t2(&Company::setCompany, this, std::move(bank.capital), std::move(bank.mainOffice), std::move(bank.listOfClients), std::move(bank.listOfWorkers));
	if (newNumbersCards < bank.newNumbersCards)
		newNumbersCards = std::move(bank.newNumbersCards);
	t1.join();
	t2.join();
}

auto Bank::findAccount(const int& numberCard) const
{
	return listOfAccount.find(numberCard);
}

/*void Bank::addMoneyToAccount(const int&& newMoneyToAccount, const long long& numberCard)
{
	auto itr = findAccount(numberCard);
	if (itr != std::end(listOfAccount))
		itr->second->addMoneyToAccount(std::move(newMoneyToAccount));
	else
		std::cout << "Bad number credit card" << std::endl;												// maybe throw exception.
}*/