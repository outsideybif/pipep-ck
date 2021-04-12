#pragma once
#include "HumanCapitalAction.h"
#include "HumanCapitalStrategy.h"
#include "HumanCapitalState.h"

class HumanCapitalLooper
{
public:
	HumanCapitalLooper(HumanCapitalStrategy* strategy, int lookingHumanCapital, 
		std::vector<HumanCapitalAction*>* actions, std::map<int, HumanCapitalState*> states);

	void SetState(short creativity = 0, short competence = 0,
		short purposefulness = 0, short communicativeness = 0,
		short motivation = 0);

	HumanCapitalStrategy* NextStep();

	double GetIndexByStrategy();

protected:
	HumanCapitalStrategy* strategy;
	int lookingHumanCapital;
	std::vector<HumanCapitalAction*>* actions = new std::vector<HumanCapitalAction*>();
	std::map<int, HumanCapitalState*> states;

	int best_steps_count = 10000000000;
	int steps_count = 0;

	unsigned long long int global_loop = 0;

	bool is_new_best_value = false;


	double normalizationFactor = 0.9;

	double new_double_of_index = 0;

	double best_human_capital = 0.0;

	short index_of_random_action;
	short index_of_best_action;

	int global_count_coef = 0;

	double test1 = 0, 
		test2 = 0, 
		test3 = 0, 
		test4 = 0, 
		test5 = 0;

};

