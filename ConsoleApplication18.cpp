// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnitTests/bankTest.h"
#include "UnitTests/clientTest.h"
#include "UnitTests/humanTest.h"
#include "UnitTests/workerTest.h"
#include "UnitTests/euroTest.h"
#include "UnitTests/accountTest.h"
#include "UnitTests/creditCardTest.h"
#include "UnitTests/usdTest.h"


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

