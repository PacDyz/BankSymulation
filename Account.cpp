#include "stdafx.h"
#include "Account.h"


Account::Account(const long long& numberAccount,
	const int& clientMoney,
	const std::string& password) :
	numberAccount(numberAccount),
	moneyInAccount(clientMoney),
	password(password){}

Account::~Account(){}
