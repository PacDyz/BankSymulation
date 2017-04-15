#pragma once
#include <memory>
class GeneratorNumberCard
{
public:
	static auto &getInstance();
	GeneratorNumberCard(GeneratorNumberCard const&) = delete;            
	GeneratorNumberCard(GeneratorNumberCard&&) = delete;               
	GeneratorNumberCard& operator=(GeneratorNumberCard const&) = delete;  
	GeneratorNumberCard& operator=(GeneratorNumberCard &&) = delete;     
	~GeneratorNumberCard();
private:
	GeneratorNumberCard();
	static std::unique_ptr<GeneratorNumberCard> instance;
	long long countNumbersCards;
};


