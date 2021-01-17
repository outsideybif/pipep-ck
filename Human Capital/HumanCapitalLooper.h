#pragma once
#include "HumanCapitalAction.h"
#include "HumanCapitalStrategy.h"
#include "HumanCapitalState.h"

class HumanCapitalLooper
{
public:
	HumanCapitalLooper(HumanCapitalStrategy* strategy, HumanCapitalStrategy* lookingStrategy, 
		std::vector<HumanCapitalAction*>* actions, std::map<std::string, HumanCapitalState*> states);

	void SetState(short creativity = 0, short competence = 0,
		short purposefulness = 0, short communicativeness = 0,
		short motivation = 0);

	HumanCapitalStrategy* NextStep();

	std::string GetIndexByStrategy(HumanCapitalStrategy* strategy);

protected:
	HumanCapitalStrategy* strategy;
	HumanCapitalStrategy* lookingStrategy;
	std::vector<HumanCapitalAction*>* actions = new std::vector<HumanCapitalAction*>();
	std::map<std::string, HumanCapitalState*> states;



	double normalizationFactor = 0.9;
};

