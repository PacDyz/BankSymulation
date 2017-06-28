#include "stdafx.h"
#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface()
{
}
int UserInterface::chooseTypeCard()
{
	int typeOfCard;
	std::cout << "Which card do you want?" << "\n";		// MOCK MOCK MOCK 
	std::cout << "Credit card? (1)" << "\n";
	std::cout << "Debit card? (2)" << "\n";
	std::cin >> typeOfCard;
	return typeOfCard;
}

UserInterface::~UserInterface()
{
}
