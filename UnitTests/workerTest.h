#pragma once
#include "gtest\gtest.h"
#include "Worker.h"

class workerTest : public testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<Worker> worker;
};
void workerTest::SetUp()
{
	Human human( "Karol", "Olejniczak", 783458 );
	Client client( std::move(human) );
	worker = std::make_unique<Worker>(std::make_shared<Client>(client), 3500);
}

TEST_F(workerTest, shouldChangeSalaryforWorker)
{
	worker->changeSalary(3700);
}

