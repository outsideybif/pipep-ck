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
	auto max_value = *std::max_element(this->values->begin(), this->values->end());
	return max_value.first;
}

double HumanCapitalState::GetMaxValue()
{
	auto max_value = *std::max_element(this->values->begin(), this->values->end());
	return max_value.second;
}

bool HumanCapitalState::CheckForMatch(HumanCapitalStrategy* strategy)
{
	short min_of_creativity = strategy->GetCreativity() - (strategy->GetCreativity() % 10);
	short max_of_creativity = min_of_creativity + 10;

	short min_of_competence = strategy->GetCompetence() - (strategy->GetCompetence() % 10);
	short max_of_competence = min_of_competence + 10;

	short min_of_communicativeness = strategy->GetCommunicativeness() - (strategy->GetCommunicativeness() % 10);
	short max_of_communicativeness = min_of_communicativeness + 10;

	short min_of_motivation = strategy->GetMotivation() - (strategy->GetMotivation() % 10);
	short max_of_motivation = min_of_motivation + 10;

	short min_of_purposefulness = strategy->GetPurposefulness() - (strategy->GetPurposefulness() % 10);
	short max_of_purposefulness = min_of_purposefulness + 10;

	short current_creativity = this->strategy->GetCreativity();
	short current_competence = this->strategy->GetCompetence();
	short current_communicativeness = this->strategy->GetCommunicativeness();
	short current_motivation = this->strategy->GetMotivation();
	short current_purposefulness = this->strategy->GetPurposefulness();

	if (current_creativity > min_of_creativity && current_creativity < max_of_creativity &&
		current_competence > min_of_competence && current_competence < max_of_competence &&
		current_communicativeness > min_of_communicativeness && current_communicativeness < max_of_communicativeness &&
		current_motivation > min_of_motivation && current_motivation < max_of_motivation &&
		current_purposefulness > min_of_purposefulness && current_purposefulness < max_of_purposefulness) {
		return true;
	}
	else {
		return false;
	}
}

void HumanCapitalState::SetNewValue(short index, double value)
{
	std::map<short, double>::iterator it = this->values->find(index);
	if (it != this->values->end())
		it->second = value;
}
