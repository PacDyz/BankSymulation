#include "stdafx.h"
#include "Bank.h"
#include <iostream>
#include <thread>
#include "BankCardBuilder.h"
#include "CreditCardBuilder.h"
#include "DebitCardBuilder.h"
#include "UserInterface.h"
//std::condition_variable cond;
//std::mutex mu;


//	std::unique_ptr<BankCardBuilder> chooseBuilder(const int&);
namespace
{
	std::unique_ptr<BankCardBuilder> chooseBuilder(const int& typeOfCard)
	{
		if (typeOfCard == 1)
			return std::make_unique<CreditCardBuilder>();
		else
			return std::make_unique<DebitCardBuilder>();
	}
}

Bank::~Bank() = default;

auto Bank::findAccount(const long long& numberCard) const
{
	return listOfAccount.find(numberCard);
}

BankCard Bank::createAccount(const std::shared_ptr<Client>& client, const std::string& password)
{
	long long numberCard{ newNumbersCards.back() };
	newNumbersCards.pop_back();
	auto account = std::make_unique<Account>( numberCard, 700, password );
	listOfAccount.insert(std::make_pair(numberCard, std::move(account)));
	std::unique_ptr<BankCardBuilder> bankCardBuilder = 
		chooseBuilder(1);
	BankCard bankCard(numberCard,
		client->getName(),
		client->getSurname(),
		bankCardBuilder->getTypeOfBankCard(),
		bankCardBuilder->setExpiryDate(),
		bankCardBuilder->getNameDistributorCard());
	return bankCard;
}

void Bank::addClient(const std::shared_ptr<Client>& client)
{
	//std::thread t1(&Bank::checkNumberAvailableCard, this);
	checkNumberAvailableCard();
	//std::promise<std::string> p;
	//auto password = p.get_future();
	std::string password(generator::generatePassword());
	//auto f = std::async(std::launch::async, &generator::generatePassword);
	//std::thread t5(generator::generatePassword, std::move(f));
	//t1.join();
	//t5.join();
	BankCard newBankCard(createAccount(client, password));
	//std::string password = f.get();
	//auto fu = std::async(std::launch::async, &Bank::createAccount, this,  human, password);
	//CreditCard newCreditCard;
	//std::thread t3(&Bank::createAccount, this, human, password, std::ref(newCreditCard));
	//t3.join();
	//CreditCard newCreditCard = fu.get();
	//std::thread t2(&Client::setCreditCard, *client, newCreditCard, password);						// change first argument...
	//t2.join();
	client->setBankCard(newBankCard, password);
	listOfClients.insert(std::make_pair(client->getPesel(), client));
}

void Bank::addMoneyToAccount(const int&& newMoneyToAccount, const long long& numberCard)
{
	auto itr(findAccount(numberCard));
	if (itr != std::end(listOfAccount))
		itr->second->addMoneyToAccount(std::move(newMoneyToAccount));
	else
		std::cout << "Bad number credit card" << "\n";												// maybe throw exception.
}

void Bank::checkNumberAvailableCard() {
	if (newNumbersCards.empty())
	{
		//t1 = std::thread(&Bank::fillInAvailableNumberCard, this);
		//auto fut = std::async(std::launch::async, &Bank::fillInAvailableNumberCard, this);
		fillInAvailableNumberCard();

	}
}

void Bank::displayStateAccount(const long long& numberCard)
{
	auto itr(findAccount(numberCard));
	if (itr != std::end(listOfAccount))
		itr->second->displayNumberMoney();
	else
		std::cout << "Bad number credit card" << "\n";
}

void Bank::fillInAvailableNumberCard()
{
	newNumbersCards = std::move(generator::generateNumberCard());
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
	/*moveAccount(std::move(bank.listOfAccount));
	setCompany(std::move(bank.capital), std::move(bank.mainOffice), std::move(bank.listOfClients), std::move(bank.listOfWorkers));
	if (newNumbersCards < bank.newNumbersCards)
		newNumbersCards = std::move(bank.newNumbersCards);*/
}
