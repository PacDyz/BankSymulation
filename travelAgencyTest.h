#pragma once

#include "gtest\gtest.h"
#include "TravelAgency.h"
#include "Human.h"
#include <memory>
class travelAgencyTest : public testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<TravelAgency> travelAgency;
};

void travelAgencyTest::SetUp()
{
	travelAgency = std::make_unique<TravelAgency>(Euro(10000), "Zielona Gora");
}

TEST_F(travelAgencyTest, schouldCreateClient)
{
	Human human("Karol", "Olejniczak", 963748234);
	std::shared_ptr<Client> client (std::make_shared<Client>(human));
	travelAgency->addClient(client);
}