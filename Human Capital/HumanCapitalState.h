#pragma once
#include "HumanCapitalAction.h"

class HumanCapitalState
{
public:
	HumanCapitalState(HumanCapitalStrategy* strategy, std::vector<HumanCapitalAction*>* actions);

	short GetMaxValueIndex();
	double GetMaxValue();
	bool CheckForMatch(double lookingHumanCapital);

	void SetNewValue(short index, double value);

	void PrintStatistics();

	double MatchResult(double lookingHumanCapital);

protected:
	HumanCapitalStrategy* strategy;
	std::vector<HumanCapitalAction*>* actions = new std::vector<HumanCapitalAction*>();

	std::map<short, double>* values = new std::map<short, double>();


	double currentMax;
	double arg_max;
};

