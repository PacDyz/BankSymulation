#pragma once
#include "gtest/gtest.h"
#include "BankCard.h"
#include <memory>
#include "Client.h"
#include <iostream>
class bankCardTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<BankCard> bankCard;
};

void bankCardTest::SetUp()
{
	bankCard = std::make_unique<BankCard>(346554645656464, "Karol", "Olejniczak", "Visa", "19/18", "credit card");
}

TEST_F(bankCardTest, schouldGetBasicInformationAboutCreditCard)
{
	ASSERT_EQ(346554645656464, bankCard->getNumberCard());
	ASSERT_EQ("Karol", bankCard->getName());
	ASSERT_EQ("Olejniczak", bankCard->getSurname());
	ASSERT_EQ("Visa", bankCard->getTypeOfBankCard());
	ASSERT_EQ("19/18", bankCard->getExpiryDate());
}
TEST(cardTest, schouldDisplayInformationAboutCreditCard)
{
	BankCard newBankCard( 346554645656464, "Karol", "Olejniczak", "Visa", "19/18", "credit card" );
	std::cout << newBankCard;
}