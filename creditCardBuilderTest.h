#pragma once
#include "gtest/gtest.h"
#include "CreditCardBuilder.h"
class creditCardBuilderTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<CreditCardBuilder> creditCardBuilder;
};
void creditCardBuilderTest::SetUp()
{
	creditCardBuilder = std::make_unique<CreditCardBuilder>();
}
TEST_F(creditCardBuilderTest, schouldGetTypeOfBankCard)
{
	EXPECT_EQ(creditCardBuilder->getTypeOfBankCard(), "credit card");
}
TEST_F(creditCardBuilderTest, schouldGetNameCard)
{
	EXPECT_EQ(creditCardBuilder->getNameDistributorCard(), "visa");
}