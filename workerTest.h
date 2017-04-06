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
	worker = std::make_unique<Worker>(Client(Human("Karol", "Olejniczak", 783458), 8758), std::make_unique<Bank>(10000, "Zielona Gora"), 3500);
}

TEST_F(workerTest, schouldChangeSalaryforWorker)
{
	worker->changeSalary(3700);
}