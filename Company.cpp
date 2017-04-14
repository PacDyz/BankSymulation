#include "stdafx.h"
#include "Company.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <numeric>
#include <iostream>
#include <thread>

std::string generator::generatePassword() 
{
	std::srand(static_cast<unsigned int>(time(nullptr)));
	unsigned int lenghtPassword = std::rand() % 15 + 5;
	std::string password;
	for (unsigned int i = 0; i < lenghtPassword; ++i)
	{
		password.push_back(std::rand() % 127);
	}
	return password;
}
bool Company::findClient(const int& pesel) const
{
	auto itr = listOfClients.find(pesel);
	return itr != std::end(listOfClients);
}
std::string Company::getMainOffice() const
{
	return mainOffice;
}

int Company::getNumberOfClients() const
{
	return listOfClients.size();
}
void Company::employWorker(const Human& human)
{
	auto worker = std::make_unique<Worker>(std::make_shared<Human>(human), 3500);
	listOfWorkers.insert(std::make_pair( worker->getPesel(), std::move(worker) ) );
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

std::vector<long long> generator::generateNumberCard(const long long& startNumber)
{
	std::vector<long long> vec(100);
	std::iota(std::begin(vec), std::end(vec), startNumber);
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(vec), std::end(vec), g);
	return vec;
}

void Company::displayAllClients() const
{
	for (const auto& itr : listOfClients)
		std::cout << itr.second;
}
void Company::moveClients(std::map<int, std::shared_ptr<Client>>&& listOfClients)
{
	this->listOfClients.insert(std::make_move_iterator(listOfClients.begin()), std::make_move_iterator(listOfClients.end()));
	listOfClients.clear();
}
void Company::moveWorkers(std::map<int, std::unique_ptr<Worker>>&& listOfWorkers)
{
	this->listOfWorkers.insert(std::make_move_iterator(listOfWorkers.begin()), std::make_move_iterator(listOfWorkers.end()));
	listOfWorkers.clear();
}
void Company::setCompany(const int&& capital, 
						const std::string&& mainOffice,
						std::map<int, std::shared_ptr<Client>>&& listOfClients,
						std::map<int, std::unique_ptr<Worker>>&& listOfWorkers)
{
	std::thread t1(&Company::moveClients, this, std::move(listOfClients));
	std::thread t2(&Company::moveWorkers, this, std::move(listOfWorkers));
	this->capital += capital;
	this->office = mainOffice;
	t1.join();
	t2.join();
}

Company::~Company() = default;
