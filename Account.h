#pragma once
#include "Bank.h"
class Account
{
public:
	Account(const long long& numberAccount, 
		const int& clientMoney, 
		const std::string& password) : 
		numberAccount(numberAccount), 
		moneyInAccount(clientMoney),
		password(password)
									  {}
	~Account();
private:
	long long numberAccount;
	int moneyInAccount;
	std::string password;
};

