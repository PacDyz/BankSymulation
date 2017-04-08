#pragma once
#include <gtest\gtest.h>
#include "Euro.h"
#include <memory>
class euroTest : public testing::Test
{
public:
	virtual void SetUp();
protected:
	std::unique_ptr<Euro> euro1;
};


void euroTest::SetUp()
{
	euro1 = std::make_unique<Euro>(100);
}

TEST_F(euroTest, shouldAddTwoEuro)
{
	Euro euro1{ 25 };
	Euro euro2{ 75 };
	Euro euro3{ 100 };
	euro1 + std::move(euro2);
	EXPECT_EQ(euro3, euro1);
}