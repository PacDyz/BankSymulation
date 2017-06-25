#pragma once
#include <gtest\gtest.h>
#include "USD.h"
#include <memory>
class usdTest : public testing::Test
{
public:
	virtual void SetUp();
protected:
	std::unique_ptr<USD> usd;
};


void usdTest::SetUp()
{
	usd = std::make_unique<USD>(100);
}

TEST_F(usdTest, shouldAddTwoEuro)
{
	USD usd1( 25 );
	USD usd2( 75 );
	USD usd3( 100 );
	usd1 += std::move(usd2);
	EXPECT_EQ(usd3, usd1);
}