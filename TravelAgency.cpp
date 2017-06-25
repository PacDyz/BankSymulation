#include "stdafx.h"
#include "TravelAgency.h"



void TravelAgency::addClient(const Human& human)
{
	auto client(std::make_unique<Client>(std::move(human)));
	listOfClients.insert(std::make_pair(client->getPesel(), std::move(client)));
}

TravelAgency::~TravelAgency() = default;