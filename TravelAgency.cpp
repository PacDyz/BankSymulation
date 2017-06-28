#include "stdafx.h"
#include "TravelAgency.h"



void TravelAgency::addClient(const std::shared_ptr<Client>& client)
{
	auto agencyClient(client);
	listOfClients.insert(std::make_pair(agencyClient->getPesel(), agencyClient));
}

TravelAgency::~TravelAgency() = default;