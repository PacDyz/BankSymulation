#include "stdafx.h"
#include "Account.h"
#include <iostream>

Account::Account(const long long& numberAccount,
	const int& clientMoney,
	const std::string& password) :
	numberAccount{ numberAccount },
	moneyInAccount{ clientMoney },
	password{ password } {}

void Account::addMoneyToAccount(const int&& newMoney)
{
	moneyInAccount += newMoney;
}

void Account::displayNumberMoney()
{
	std::cout << moneyInAccount << std::endl;
}

void Account::withdrawMoneyFromAccount(const int& moneyToWithdraw)
{
	moneyInAccount -= moneyToWithdraw;
}

Account::~Account() = default;
