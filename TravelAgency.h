#pragma once
#include <string>
#include "Company.h"
class TravelAgency : public Company
{
public:
	template<typename T>
	TravelAgency(T&&, const std::string&);
	template<>
	TravelAgency(int&& capital, const std::string& mainOffice);
	~TravelAgency();
};



template<typename T>
TravelAgency::TravelAgency(T&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice) {}

template<>
TravelAgency::TravelAgency(int&& capital, const std::string& mainOffice) : Company(std::move(capital), mainOffice)  {}
