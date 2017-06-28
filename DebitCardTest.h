#pragma once
#include <memory>
#include "DebitCard.h"
#include <gtest\gtest.h>
class debitCardTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<DebitCard> debitCard;
};

void debitCardTest::SetUp()
{
	debitCard = std::make_unique<DebitCard>(346554645656464, "Karol", "Olejniczak", "Visa", "19/18", 1000);
}
