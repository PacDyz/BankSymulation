#pragma once
class Money
{
public:
	Money(int value) :value(value) {};
	Money(const Money&) = delete;
	Money &operator=(const Money&) = delete;
	//virtual Money &operator+(Money&&) = 0;
	//virtual Money &operator-(Money&&) = 0;
	//virtual bool operator==(const Money&) const = 0;
	virtual ~Money();
protected:
	int value;
};

