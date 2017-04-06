#pragma once
#include "gtest\gtest.h"
#include "Bank.h"
#include <memory>
class bankTest : public testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<Bank> bank;
};
void bankTest::SetUp()
{
	bank = std::make_unique<Bank>(100000, "Zielona Gora");
}

TEST_F(bankTest, schouldAddCapitalToTheBank)
{
	bank->setCapital(154);
}

TEST_F(bankTest, schouldAddClients)
{
	Human human("Karol", "Olejniczak", 963748234);
	bank->addClient( human);
}

TEST_F(bankTest, schouldFindClient)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Wojtek", "Danielewski", 9352453);
	Human human3("Szymon", "Nowak", 8564545);
	bank->addClient(human1);
	bank->addClient(human2);
	bank->addClient(human3);
	ASSERT_TRUE(bank->findClient(human1.getPesel()));
}

TEST_F(bankTest, schouldGetMainOffice)
{
	EXPECT_EQ("Zielona Gora", bank->getMainOffice());
}

TEST_F(bankTest, schouldGetNumberOfClients)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Jacek", "Godlewski", 963748233);
	bank->addClient(human1);
	bank->addClient(human2);
	EXPECT_EQ(2, bank->getNumberOfClients());
}

TEST_F(bankTest, schouldAddNewWorker)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	bank->employWorker(client1);
}

TEST_F(bankTest, schouldAddNewWorkers)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	Client client2(Human("Jacek", "Godlewski", 963748233), 505051);
	bank->employWorker(client1);
	bank->employWorker(client2);
}

TEST_F(bankTest, schouldRemoveWorker)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	bank->employWorker(client1);
	bank->removeWorker(505050);
}

TEST_F(bankTest, schouldRemoveWorkers)
{
	Client client1(Human("Karol", "Olejniczak", 963748234), 505050);
	Client client2(Human("Jacek", "Godlewski", 963748233), 505051);
	bank->employWorker(client1);
	bank->employWorker(client2);
	bank->removeWorker(505050);
	bank->removeWorker(505051);
	bank->employWorker(client1);
	bank->removeWorker(505051);
}
TEST_F(bankTest, schouldRemoveClients)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Jacek", "Godlewski", 963748233);
	bank->addClient(human1);
	bank->addClient(human2);
	bank->removeClient(963748234);
	bank->removeClient(963748233);
	bank->addClient(human1);
	bank->removeClient(963748234);
}