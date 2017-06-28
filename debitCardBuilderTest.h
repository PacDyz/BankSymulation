#pragma once
#include "gtest/gtest.h"
#include "DebitCardBuilder.h"
class debitCardBuilderTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<DebitCardBuilder> debitCardBuilder;
};
void debitCardBuilderTest::SetUp()
{
	debitCardBuilder = std::make_unique<DebitCardBuilder>();
}
TEST_F(debitCardBuilderTest, schouldGetTypeOfBankCard)
{
	EXPECT_EQ(debitCardBuilder->getTypeOfBankCard(), "debit card");
}
TEST_F(debitCardBuilderTest, schouldGetNameCard)
{
	EXPECT_EQ(debitCardBuilder->getNameDistributorCard(), "mastercard");
}