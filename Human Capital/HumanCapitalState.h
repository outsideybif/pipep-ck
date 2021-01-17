#pragma once
#include "HumanCapitalAction.h"

class HumanCapitalState
{
public:
	HumanCapitalState(HumanCapitalStrategy* strategy, std::vector<HumanCapitalAction*>* actions);

	short GetMaxValueIndex();
	double GetMaxValue();
	bool CheckForMatch(HumanCapitalStrategy* strategy);

	void SetNewValue(short index, double value);

protected:
	HumanCapitalStrategy* strategy;
	std::vector<HumanCapitalAction*>* actions = new std::vector<HumanCapitalAction*>();

	std::map<short, double>* values = new std::map<short, double>();

};

