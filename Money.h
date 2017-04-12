#pragma once
#include <memory>


class Money
{
public:
	Money(const int&, const double&);
	Money(const double&);
	Money(const Money&) = delete;
	Money(Money&&) :value(std::move(value)) {};
	double getNominalValue() const;
	int getValue() const;
	Money &operator=(const Money&) = delete;
	//template<typename T, typename K>
	//K &operator=(T&&);
	//virtual Money &operator+(std::unique_ptr<Money>&&) = 0;
	//virtual Money &operator-(Money&&) = 0;
	//virtual bool operator==(const Money&) const = 0;
	virtual ~Money();
protected:
	int value;
	double nominalValue;
};
/*template<typename K, typename T>
K &Money::operator=(T&& t)
{
	K k;
	return K(t.getValue()*t.getNominalValue() / k.getNominalValue());
}*/
namespace cantor
{
	template<typename BeforeExchangeMoney, typename AfterExchangeMoney>
	decltype(auto) exchangeMoney(BeforeExchangeMoney&& moneyToExchange);
}

template<typename BeforeExchangeMoney, typename AfterExchangeMoney>
decltype(auto) cantor::exchangeMoney(BeforeExchangeMoney&& moneyToExchange)
{
	AfterExchangeMoney afterExchangeMoney;
	return AfterExchangeMoney(moneyToExchange.getValue()*moneyToExchange.getNominalValue() / afterExchangeMoney.getNominalValue());
}
