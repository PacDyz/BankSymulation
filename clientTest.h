#pragma once
#include "gtest\gtest.h"
#include "Client.h"

class clientTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<Client> client;
};

void clientTest::SetUp()
{
	client = std::make_unique<Client>(Human("Karol", "Olejniczak", 783458), 87584);
}
//TEST_F()