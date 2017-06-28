#pragma once
#include <memory>
#include "CreditCard.h"
#include <gtest\gtest.h>
class creditCardTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<CreditCard> creditCard;
};

void creditCardTest::SetUp()
{
	creditCard = std::make_unique<CreditCard>(346554645656464, "Karol", "Olejniczak", "Visa", "19/18");
}