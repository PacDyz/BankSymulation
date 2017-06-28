#pragma once
#include <string>
#include "Company.h"
class TravelAgency : public Company
{
public:
	template<typename T>
	TravelAgency(const T&&, const std::string&);
	template<>
	TravelAgency(const int&& capital, const std::string& mainOffice);
	void addClient(const std::shared_ptr<Client>&);
	~TravelAgency();
};



template<typename T>
TravelAgency::TravelAgency(const T&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice) {}

template<>
TravelAgency::TravelAgency(const int&& capital, const std::string& mainOffice) : Company(std::move(capital), mainOffice)  {}
