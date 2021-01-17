#include "includes.h"

HumanCapitalLooper::HumanCapitalLooper(HumanCapitalStrategy* strategy, HumanCapitalStrategy* lookingStrategy, 
	std::vector<HumanCapitalAction*>* actions, std::map<std::string, HumanCapitalState*> states)
{
	this->strategy = strategy;
	this->actions = actions;
	this->states = states;
	this->lookingStrategy = lookingStrategy;
}

void HumanCapitalLooper::SetState(short creativity, short competence, short purposefulness, short communicativeness, short motivation)
{
	strategy->SetCreativity(creativity);
	strategy->SetCompetence(competence);
	strategy->SetPurposefulness(purposefulness);
	strategy->SetCommunicativeness(communicativeness);
	strategy->SetMotivation(motivation);
}

HumanCapitalStrategy* HumanCapitalLooper::NextStep()
{

	//std::cout << "=======\n";
	
	short index_of_random_action = rand() % 4 + 1;
	short index_of_best_action;

	std::string current_string_of_index = this->GetIndexByStrategy(this->strategy);
	HumanCapitalState* current_state = this->states.at(current_string_of_index);

	if (index_of_random_action == 2) {
		index_of_best_action = rand() % this->actions->size();
	}
	else {
		
		index_of_best_action = current_state->GetMaxValueIndex();
	}
	


	
	//this->strategy->PrintData();
	
	HumanCapitalAction* next_action = this->actions->at(index_of_best_action);

	this->strategy->ApplyAction(next_action);
	std::string new_string_of_index = this->GetIndexByStrategy(this->strategy);
	HumanCapitalState* new_state = this->states.at(new_string_of_index);

	//std::cout << "------\n";

	this->strategy->PrintData();

	short reward = new_state->CheckForMatch(this->lookingStrategy) ? 0 : -1;
	double new_value = reward + this->normalizationFactor * new_state->GetMaxValue();

	current_state->SetNewValue(index_of_best_action, new_value);

	if (reward == 0) {
		this->strategy->Reset();
	}

	//std::cout << "=======\n";

	return this->strategy;
}

std::string HumanCapitalLooper::GetIndexByStrategy(HumanCapitalStrategy* strategy)
{
	short normalize_creativity = (this->strategy->GetCreativity() - (this->strategy->GetCreativity() % 10)) / 10 - 15;
	short normalize_competence = (this->strategy->GetCompetence() - (this->strategy->GetCompetence() % 10)) / 10 - 15;
	short normalize_purposefulness = (this->strategy->GetPurposefulness() - (this->strategy->GetPurposefulness() % 10)) / 10 - 15;
	short normalize_communicativeness = (this->strategy->GetCommunicativeness() - (this->strategy->GetCommunicativeness() % 10)) / 10 - 15;
	short normalize_motivation = (this->strategy->GetMotivation() - (this->strategy->GetMotivation() % 10)) / 10 - 15;


	std::stringstream string_of_index;
	string_of_index << normalize_creativity << "," << normalize_competence << ","
		<< normalize_purposefulness << "," << normalize_communicativeness << "," << normalize_motivation;

	return string_of_index.str();
}

