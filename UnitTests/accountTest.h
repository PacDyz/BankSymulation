#pragma once
#include "gtest\gtest.h"
#include "Bank.h"
#include "Account.h"
#include <memory>
class accountTest : public testing::Test
{
protected:
	virtual void SetUp();

	std::unique_ptr<Account> account;
};
void accountTest::SetUp()
{
	account = std::make_unique<Account>(654646, 500, "password");
}

TEST_F(accountTest, schouldAddMoneyToAccount)
{
	account->addMoneyToAccount(400);
}

TEST_F(accountTest, schouldDisplayMoneyThatAreInAccount)
{
	account->displayNumberMoney();
}

TEST_F(accountTest, schouldCanWithdrawMoneyFromAccount)
{
	account->withdrawMoneyFromAccount(500);
}

TEST_F(accountTest, schouldDisplay900InAccount)
{
	account->addMoneyToAccount(400);
	account->displayNumberMoney();
}

TEST_F(accountTest, schouldDisplayStartValueMoneyInAccount)
{
	account->addMoneyToAccount(400);
	account->withdrawMoneyFromAccount(400);
	account->displayNumberMoney();
}
