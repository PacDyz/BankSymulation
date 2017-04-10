#pragma once
#include <string>

class Account
{
public:
	Account(const long long& ,
		const int&,
		const std::string&);
	~Account();
private:
	long long numberAccount;
	int moneyInAccount;
	std::string password;
};

