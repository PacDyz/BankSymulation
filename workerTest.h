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
	Human human("Karol", "Olejniczak", 783458);
	Client client(human, 8758);
	worker = std::make_unique<Worker>(client, 3500);
}

TEST_F(workerTest, schouldChangeSalaryforWorker)
{
	worker->changeSalary(3700);
}

