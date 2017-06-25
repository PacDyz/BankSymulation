#pragma once
#include "Account.h"
#include "Company.h"

class Bank : public Company
{
public:
	template<typename T>
	Bank(const T&&, const std::string&);
	template<>
	Bank(const int&&, const std::string&);
	// template <typename T> 
	// Bank(std::initializer_list<T> il) = delete; this is reason why i don't use {} with constructor
	//										if i did this, i must write this 2 lines in all class
	CreditCard createAccount(const Human&, const std::string&);
	void addClient(const Human&) override;
	void addMoneyToAccount(const int&&, const long long&);
	void checkNumberAvailableCard();
	void displayStateAccount(const long long&);
	void fillInAvailableNumberCard();
	auto findAccount(const long long& numberCard) const;
	void moveAccount(std::map<long long, std::unique_ptr<Account>>&&);
	void setBank(Bank&&);
	~Bank();
private:
	std::map<long long, std::unique_ptr<Account>> listOfAccount;
	std::vector<long long> newNumbersCards;
};

template<typename T>
Bank::Bank(const T&& capital, const std::string& mainOffice) :Company(std::move(capital), mainOffice){}

template<>
Bank::Bank(const int&& capital, const std::string& mainOffice) : Company(std::move(capital), mainOffice){}

