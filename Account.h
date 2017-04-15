#pragma once
#include <string>

class Account
{
public:
	Account(const long long& ,
		const int&,
		const std::string&);
	void addMoneyToAccount(const int&&);
	void displayNumberMoney();
	void withdrawMoneyFromAccount(const int&);
	~Account();
private:
	long long numberAccount;
	int moneyInAccount;
	std::string password;
};

