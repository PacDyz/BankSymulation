#include "stdafx.h"
#include "Company.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <thread>

int generator::getRandomNumber(const int& begin, const int& end)
{
	std::uniform_int_distribution<> uid(begin, end);
	static std::random_device rd;
	static std::mt19937 g{ rd() };
	unsigned int randomNumber( uid(g) );
	return randomNumber;
}

std::string generator::generatePassword() 
{
	std::string password;
	for (unsigned int i = 0; i < generator::getRandomNumber(5, 15); ++i)
	{
		std::uniform_int_distribution<> uidChar(0, 100);
		password.push_back(generator::getRandomNumber(0, 127));
	}
	return password;
}

std::vector<long long> generator::generateNumberCard()
{
	std::vector<long long> vec(100);
	std::iota(std::begin(vec), std::end(vec), counterNumbersCards);
	std::random_device rd;
	std::mt19937 g{ rd() };
	std::shuffle(std::begin(vec), std::end(vec), g);
	counterNumbersCards += 100;
	return vec;
}

int Company::getNumberOfClients() const
{
	return listOfClients.size();
}

std::shared_ptr<Client> Company::findClient(const int& pesel) const
{
	auto itr{ listOfClients.find(pesel) };
	return itr->second;
}

std::string Company::getMainOffice() const
{
	return mainOffice;
}


void Company::displayAllClients() const
{
	for (const auto& itr : listOfClients)
		std::cout << itr.second;
}

void Company::employWorker( std::shared_ptr<Human> human)
{
	auto worker{ std::make_unique<Worker>(human, 3500) };
	listOfWorkers.insert(std::make_pair( worker->getPesel(), std::move(worker) ) );
}

void Company::moveClients(std::map<int, std::shared_ptr<Client>>&& listOfClients)
{
	this->listOfClients.insert(std::make_move_iterator(listOfClients.begin()),
								std::make_move_iterator(listOfClients.end()));
	listOfClients.clear();
}
void Company::moveWorkers(std::map<int, std::unique_ptr<Worker>>&& listOfWorkers)
{
	this->listOfWorkers.insert(std::make_move_iterator(listOfWorkers.begin()),
								std::make_move_iterator(listOfWorkers.end()));
	listOfWorkers.clear();
}

void Company::removeClient(const int& pesel)
{
	listOfClients.erase(pesel);
}


void Company::removeWorker(const int& pesel)
{
	listOfWorkers.erase(pesel);
}

void Company::setCapital(const int& newCapital)
{
	capital = newCapital;
}

void Company::setCompany(const int&& capital, 
						const std::string&& mainOffice,
						std::map<int, std::shared_ptr<Client>>&& listOfClients,
						std::map<int, std::unique_ptr<Worker>>&& listOfWorkers)
{
	std::thread t1{ &Company::moveClients, this, std::move(listOfClients) };
	std::thread t2{ &Company::moveWorkers, this, std::move(listOfWorkers) };
	this->capital += capital;
	this->office.emplace_back(std::move(mainOffice));
	t1.join();
	t2.join();
}

Company::~Company() = default;
