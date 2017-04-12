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
	bank = std::make_unique<Bank>(Euro(10000), "Zielona Gora");
}

TEST_F(bankTest, shouldAddCapitalToTheBank)
{
	bank->setCapital(154);
}

TEST_F(bankTest, shouldAddClients)
{
	Human human("Karol", "Olejniczak", 963748234);
	bank->addClient(human);
}

TEST_F(bankTest, shouldFindClient)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Wojtek", "Danielewski", 9352453);
	Human human3("Szymon", "Nowak", 8564545);
	bank->addClient(human1);
	bank->addClient(human2);
	bank->addClient(human3);
	ASSERT_TRUE(bank->findClient(963748234));
}

TEST_F(bankTest, shouldGetMainOffice)
{
	EXPECT_EQ("Zielona Gora", bank->getMainOffice());
}

TEST_F(bankTest, shouldGetNumberOfClients)
{
	Human human1("Karol", "Olejniczak", 963748234);
	Human human2("Jacek", "Godlewski", 963748233);
	bank->addClient(human1);
	bank->addClient(human2);
	EXPECT_EQ(2, bank->getNumberOfClients());
}

TEST_F(bankTest, shouldAddNewWorker)
{
	Client client1(Human("Karol", "Olejniczak", 963748234));
	bank->employWorker(client1);
}

TEST_F(bankTest, shouldAddNewWorkers)
{
	Client client1(Human("Karol", "Olejniczak", 963748234));
	Client client2(Human("Jacek", "Godlewski", 963748233));
	bank->employWorker(client1);
	bank->employWorker(client2);
}

TEST_F(bankTest, shouldRemoveWorker)
{
	Client client1(Human("Karol", "Olejniczak", 963748234));
	bank->employWorker(client1);
	bank->removeWorker(963748234);
}

TEST_F(bankTest, shouldRemoveWorkers)
{
	Client client1(Human("Karol", "Olejniczak", 963748234));
	Client client2(Human("Jacek", "Godlewski", 963748233));
	bank->employWorker(client1);
	bank->employWorker(client2);
	bank->removeWorker(963748234);
	bank->removeWorker(963748233);
	bank->employWorker(client1);
	bank->removeWorker(963748234);
}
TEST_F(bankTest, shouldRemoveClients)
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
TEST_F(bankTest, schouldAddHundredOneClients)
{
	for (unsigned int i = 0; i < 101; ++i)
	{
		Human human("Karol", "Olejniczak", i);
		bank->addClient(human);
	}
	EXPECT_EQ(101, bank->getNumberOfClients());
}
TEST_F(bankTest, schouldAddThousandClients)
{
	for (unsigned int i = 0; i < 1000; ++i)
	{
		Human human("Karol", "Olejniczak", i);
		bank->addClient(human);
	}
	EXPECT_EQ(1000, bank->getNumberOfClients());
}
TEST_F(bankTest, schouldAddAndRemoveHundredOneClients)
{
	for (unsigned int i = 0; i < 101; ++i)
	{
		Human human("Karol", "Olejniczak", i);
		bank->addClient(human);
		bank->removeClient(i);
	}
	EXPECT_EQ(0, bank->getNumberOfClients());
}