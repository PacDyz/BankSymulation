#include "stdafx.h"
#include "Company.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <numeric>

Company::Company(Euro&& capital, const std::string& mainOffice) :capital(std::move(capital)), mainOffice(mainOffice) {}

std::string generator::generatePassword()
{
	srand(time(nullptr));
	unsigned int lenghtPassword = std::rand() % 15 + 5;
	std::string password;
	for (unsigned int i = 0; i < lenghtPassword; ++i)
	{
		password.push_back(std::rand() % 127);
	}
	return password;
}

std::vector<long long> generator::generateNumberCard(const long long& startNumber)
{
	std::vector<long long> vec(100);
	std::iota(std::begin(vec), std::end(vec), startNumber);
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(vec), std::end(vec), g);
	return vec;
}

Company::~Company(){}
