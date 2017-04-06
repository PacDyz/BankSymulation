#pragma once
#include "gtest\gtest.h"
#include "Bank.h"
#include <memory>
class bankTest : public testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<Bank> bankWithCapital;
};
void bankTest::SetUp()
{
	bankWithCapital = std::make_unique<Bank>(100000, "Zielona Gora");
}

TEST_F(bankTest, schouldAddCapitalToTheBank)
{
	bankWithCapital->setCapital(154);
}

TEST_F(bankTest, schouldAddClients)
{
	Human client("Karol", "Olejniczak", 963748234);
	bankWithCapital->addClient( client);
}

TEST_F(bankTest, schouldFindClient)
{
	Human client("Karol", "Olejniczak", 963748234);
	bankWithCapital->addClient(client);
	ASSERT_TRUE(bankWithCapital->findClient(client.getPesel()));
}

TEST_F(bankTest, schouldGetMainOffice)
{
	EXPECT_EQ("Zielona Gora", bankWithCapital->getMainOffice());
}

TEST_F(bankTest, schouldGetNumberOfClients)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Jacek", "Godlewski", 963748233);
	bankWithCapital->addClient(human1);
	bankWithCapital->addClient(human2);
	EXPECT_EQ(2, bankWithCapital->getNumberOfClients());
}

TEST_F(bankTest, schouldAddNewWorker)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	bankWithCapital->employWorker(client1);
}

TEST_F(bankTest, schouldAddNewWorkers)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	Client client2(Human("Jacek", "Godlewski", 963748233), 505051);
	bankWithCapital->employWorker(client1);
	bankWithCapital->employWorker(client2);
}