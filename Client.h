#pragma once
#include "Human.h"
#include "BankCard.h"
#include <memory>
class Client : public Human
{
public:
	template<typename T>
	Client(T&&);
	BankCard getCreditCard() const;
	long long getNumberCreditCard() const;
	std::string getPassword() const;
	void setBankCard(const BankCard&, const std::string&);
	~Client();
private:
	BankCard bankCard;
	std::string passwordToAccount;
};
std::ostream &operator<<(std::ostream& str, std::shared_ptr<Client>);

template<typename T>
Client::Client(T&& human) : Human(std::forward<T>(human)),
bankCard(0, "", "", "", "", ""),
passwordToAccount("") {}
