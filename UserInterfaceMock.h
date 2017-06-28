#pragma once
#include "gmock\gmock.h"
#include "UserInterface.h"
class UserInterfaceMock : public UserInterface
{
public:
	MOCK_METHOD0(chooseTypeCard, int());
};