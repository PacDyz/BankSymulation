#include "stdafx.h"
#include "BankCardBuilder.h"
#include <ctime>
#include <iostream>
BankCardBuilder::BankCardBuilder()
{
}

std::string BankCardBuilder::setExpiryDate()
{
	const int numberForYear = 1900;
	int expiryTime = 5;
	int numberForMonth = 1;
	std::time_t date = std::time(nullptr);
	tm currentDate;
	localtime_s(&currentDate, &date);
	int expiryMonth = currentDate.tm_mon + numberForMonth;
	int expiryYear = currentDate.tm_year + numberForYear + expiryTime;
	std::string expiryDate;
	if (expiryMonth < 10)
		expiryDate = "0";
	expiryDate += std::to_string(expiryMonth) + "/" + std::to_string(expiryYear);
	return expiryDate;
}
BankCardBuilder::~BankCardBuilder()
{
}
