#pragma once
#include "gtest/gtest.h"
#include "CreditCard.h"
#include <memory>
#include "Client.h"
#include <iostream>
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

TEST_F(creditCardTest, schouldGetBasicInformationAboutCreditCard)
{
	ASSERT_EQ(346554645656464, creditCard->getNumberCard());
	ASSERT_EQ("Karol", creditCard->getName());
	ASSERT_EQ("Olejniczak", creditCard->getSurname());
	ASSERT_EQ("Visa", creditCard->getTypeOfCreditCard());
	ASSERT_EQ("19/18", creditCard->getExpiryDate());
}
TEST(cardTest, schouldDisplayInformationAboutCreditCard)
{
	CreditCard newCreditCard{ 346554645656464, "Karol", "Olejniczak", "Visa", "19/18" };
	std::cout << newCreditCard;
}