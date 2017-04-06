#pragma once
#include "gtest\gtest.h"
#include "Human.h"
#include <memory>

class humanTest : public testing::Test 
{
protected:
	virtual void SetUp();

	std::unique_ptr<Human> human;
};

void humanTest::SetUp()
{
	human = std::make_unique<Human>("Karol", "Olejniczak", 10202020);
}

TEST_F(humanTest, schouldGetPesel)
{
	EXPECT_EQ(10202020, human->getPesel());
}

