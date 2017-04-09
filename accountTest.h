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
