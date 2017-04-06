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
	Human client1("Karol", "Olejniczak", 963748234);
	Human client2("Jacek", "Godlewski", 963748233);
	bankWithCapital->addClient(client1);
	bankWithCapital->addClient(client2);
	EXPECT_EQ(2, bankWithCapital->getNumberOfClients());
}