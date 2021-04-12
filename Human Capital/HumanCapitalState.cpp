#include "includes.h"

HumanCapitalState::HumanCapitalState(HumanCapitalStrategy* strategy, std::vector<HumanCapitalAction*>* actions)
{
	this->strategy = strategy;
	this->actions = actions;

	for (short i = 0; i < this->actions->size(); i++)
	{
		this->values->insert(std::make_pair(i, 0));
	}
}

short HumanCapitalState::GetMaxValueIndex()
{
	currentMax = this->values->cbegin()->second;
	arg_max = this->values->cbegin()->first;
	for (auto it = this->values->cbegin(); it != this->values->cend(); ++it)
	{
		if (it->second > currentMax) {
			arg_max = it->first;
			currentMax = it->second;
		}
	}
	return arg_max;
}

double HumanCapitalState::GetMaxValue()
{
	currentMax = this->values->cbegin()->second;
	arg_max = this->values->cbegin()->first;



	for (auto it = this->values->cbegin(); it != this->values->cend(); ++it)
	{
		if (it->second > currentMax) {
			arg_max = it->first;
			currentMax = it->second;
		}
	}
	return currentMax;
}

bool HumanCapitalState::CheckForMatch(double lookingHumanCapital)
{
	
	if (this->strategy->CalculateHumanCapital() >= lookingHumanCapital) {
		return true;
	}
	else {
		return false;
	}
}

double HumanCapitalState::MatchResult(double lookingHumanCapital)
{
	return lookingHumanCapital - this->strategy->CalculateHumanCapital();
}



void HumanCapitalState::SetNewValue(short index, double value)
{
	std::map<short, double>::iterator it = this->values->find(index);
	if (it != this->values->end())
		it->second = value;
}

void HumanCapitalState::PrintStatistics()
{
	std::cout << "-------\n";

	for (std::map<short, double>::iterator it = this->values->begin(); it != this->values->end(); ++it)
	{
		std::cout << it->first << ":" << it->second << "\n";
		
	}
	

	std::cout << "-------\n";
		
}
