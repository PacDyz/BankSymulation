#pragma once
#include <memory>

class Money
{
public:
	Money(const int& value) :value(value) {};
	Money(const Money&) = delete;
	Money &operator=(const Money&) = delete;
	Money(Money&&) :value(std::move(value)) {};
	//virtual Money &operator+(std::unique_ptr<Money>&&) = 0;
	//virtual Money &operator-(Money&&) = 0;
	//virtual bool operator==(const Money&) const = 0;
	virtual ~Money();
protected:
	int value;
};
