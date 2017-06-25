#pragma once
#include "gtest\gtest.h"
#include "Bank.h"
#include <memory>
#include <iostream>
class bankTest : public testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<Bank> bank;
};
void bankTest::SetUp()
{
	bank = std::make_unique<Bank>(Euro( 10000 ), "Zielona Gora");
}

TEST_F(bankTest, shouldAddCapitalToTheBank)
{
	bank->setCapital(154);
}

TEST_F(bankTest, shouldAddClients)
{
	Human human( "Karol", "Olejniczak", 963748234 );
	bank->addClient(human);
}

TEST_F(bankTest, shouldFindClient)
{
	Human human1( "Karol", "Olejniczak", 963748234 );
	Human human2( "Wojtek", "Danielewski", 9352453 );
	Human human3( "Szymon", "Nowak", 8564545 );
	bank->addClient(human1);
	bank->addClient(human2);
	bank->addClient(human3);
	auto client(bank->findClient(963748234));
	EXPECT_EQ(963748234, client->getPesel());
}

TEST_F(bankTest, shouldGetMainOffice)
{
	EXPECT_EQ("Zielona Gora", bank->getMainOffice());
}

TEST_F(bankTest, shouldGetNumberOfClients)
{
	Human human1( "Karol", "Olejniczak", 963748234 );
	Human human2( "Jacek", "Godlewski", 963748233 );
	bank->addClient(human1);
	bank->addClient(human2);
	EXPECT_EQ(2, bank->getNumberOfClients());
}

TEST_F(bankTest, shouldAddNewWorker)
{
	Client client1( Human( "Karol", "Olejniczak", 963748234 ) );
	auto client(std::make_shared<Client>(client1));
	bank->employWorker(client);
}

TEST_F(bankTest, shouldAddNewWorkers)
{
	Client client1( Human( "Karol", "Olejniczak", 963748234 ) );
	Client client2( Human( "Jacek", "Godlewski", 963748233 ) );
	auto client1ptr(std::make_shared<Client>(client1));
	auto client2ptr(std::make_shared<Client>(client2));
	bank->employWorker(client1ptr);
	bank->employWorker(client2ptr);
}

TEST_F(bankTest, shouldRemoveWorker)
{
	Client client1( Human( "Karol", "Olejniczak", 963748234 ) );
	auto client(std::make_shared<Client>(client1));
	bank->employWorker(client);
	bank->removeWorker(963748234);
}

TEST_F(bankTest, shouldRemoveWorkers)
{
	Client client1( Human("Karol", "Olejniczak", 963748234 ) );
	Client client2( Human("Jacek", "Godlewski", 963748233) );
	auto client1ptr1(std::make_shared<Client>(client1));
	auto client2ptr(std::make_shared<Client>(client2));
	bank->employWorker(client1ptr1);
	bank->employWorker(client2ptr);
	bank->removeWorker(963748234);
	bank->removeWorker(963748233);
	auto client1ptr2(std::make_shared<Client>(client1));
	bank->employWorker(client1ptr2);
	bank->removeWorker(963748234);
}
TEST_F(bankTest, shouldRemoveClients)
{
	Human human1( "Karol", "Olejniczak", 963748234 );
	Human human2( "Jacek", "Godlewski", 963748233 );
	bank->addClient(human1);
	bank->addClient(human2);
	bank->removeClient(963748234);
	bank->removeClient(963748233);	
	bank->addClient(human1);
	bank->removeClient(963748234);
}
TEST_F(bankTest, schouldAddHundredOneClients)
{
	for (int i = 0; i < 101; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank->addClient(human);
	}
	EXPECT_EQ(101, bank->getNumberOfClients());
}
TEST_F(bankTest, schouldAddThousandClients)
{
	for (int i = 0; i < 1000; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank->addClient(human);
	}
	EXPECT_EQ(1000, bank->getNumberOfClients());
}

TEST_F(bankTest, schouldAddAndRemoveHundredOneClients)
{
	for (int i = 0; i < 101; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank->addClient(human);
		bank->removeClient(i);
	}
	EXPECT_EQ(0, bank->getNumberOfClients());
}

TEST_F(bankTest, schouldShowAllClients)
{
	for (int i = 0; i < 10; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank->addClient(human);
	}
	bank->displayAllClients();
}
TEST_F(bankTest, schouldMoveBank)
{
	Bank bank1( Euro( 10000 ), "Zielona Gora" );
	for (int i = 0; i < 101; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank1.addClient(human);
	}
	Bank bank2( Euro( 7000 ), "Wroclaw" );
	for (int i = 101; i < 602; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank1.addClient(human);
	}
	bank1.setBank(std::move(bank2));
}

TEST_F(bankTest, schouldSetMoneyToClientAccount)
{
	Human human( "Karol", "Olejniczak", 963748234 );
	bank->addClient(human);
	auto client = bank->findClient(963748234);
	bank->addMoneyToAccount(500, client->getNumberCreditCard());
	bank->displayStateAccount(client->getNumberCreditCard()); 
}

TEST_F(bankTest, schouldMoveBankWithAbout5900Clients)
{
	Bank bank1( Euro( 10000 ), "Zielona Gora" );
	for (int i = 0; i < 101; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank1.addClient(human);
	}
	Bank bank2( Euro( 7000 ), "Wroclaw" );
	for (int i = 101; i < 6020; ++i)
	{
		Human human( "Karol", "Olejniczak", i );
		bank1.addClient(human);
	}
	bank1.setBank(std::move(bank2));
}