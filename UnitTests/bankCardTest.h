#pragma once
#include "gtest/gtest.h"
#include "bankCard.h"
#include <memory>
#include "Client.h"
#include <iostream>
class creditCardTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<BankCard> bankCard;
};

void creditCardTest::SetUp()
{
	bankCard = std::make_unique<BankCard>(346554645656464, "Karol", "Olejniczak", "Visa", "19/18");
}

TEST_F(creditCardTest, schouldGetBasicInformationAboutCreditCard)
{
	ASSERT_EQ(346554645656464, bankCard->getNumberCard());
	ASSERT_EQ("Karol", bankCard->getName());
	ASSERT_EQ("Olejniczak", bankCard->getSurname());
	ASSERT_EQ("Visa", bankCard->getTypeOfCreditCard());
	ASSERT_EQ("19/18", bankCard->getExpiryDate());
}
TEST(cardTest, schouldDisplayInformationAboutCreditCard)
{
	BankCard newCreditCard( 346554645656464, "Karol", "Olejniczak", "Visa", "19/18" );
	std::cout << newCreditCard;
}