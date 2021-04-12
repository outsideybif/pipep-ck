#include "includes.h"

HumanCapitalLooper::HumanCapitalLooper(HumanCapitalStrategy* strategy, int lookingHumanCapital,
	std::vector<HumanCapitalAction*>* actions, std::map<int, HumanCapitalState*> states)
{
	this->strategy = strategy;
	this->actions = actions;
	this->states = states;
	this->lookingHumanCapital = lookingHumanCapital;
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
	this->steps_count++;
	this->global_loop++;

	this->index_of_random_action = rand() % 6 + 1;
	this->index_of_best_action;

	double current_string_of_index = this->GetIndexByStrategy();
	HumanCapitalState* current_state = this->states.at(current_string_of_index);

	if (index_of_random_action == 2) {
		this->index_of_best_action = rand() % this->actions->size();
	}
	else {
		this->index_of_best_action = current_state->GetMaxValueIndex();
	}
	
	HumanCapitalAction* next_action = this->actions->at(this->index_of_best_action);
	this->strategy->ApplyAction(next_action);
	this->new_double_of_index = this->GetIndexByStrategy();
	HumanCapitalState* new_state = this->states.at(this->new_double_of_index);

	/*double reward = new_state->CheckForMatch(this->lookingHumanCapital) ? 0.0 : -1.0;
	bool is_end = false;
	if (reward >= 0) {


		is_end = true;
		if (this->steps_count >= this->best_steps_count) {
			reward = this->steps_count > this->best_steps_count ? -1.5 : 0.0;
			this->is_new_best_value = false;
		}
		else {
			reward = 1.0;
			this->best_steps_count = this->steps_count;
			this->test1 = this->strategy->GetSalaryInvesting();
			this->test2 = this->strategy->GetEducationInvesting();
			this->test3 = this->strategy->GetHealthInvesting();
			this->test4 = this->strategy->GetCulturalInvesting();
			this->test5 = this->strategy->GetInformationInvesting();
			this->is_new_best_value = true;
		}
	}*/


	

	double reward = new_state->CheckForMatch(this->lookingHumanCapital) ? 0 : -1;
	bool is_end = false;
	if (reward >= 0) {
		double human_capital = this->strategy->CalculateHumanCapital();
		is_end = true;
		if (this->strategy->GetTotalHumanCapitalInvesting() > this->strategy->GetBudget() &&
			this->steps_count >= this->best_steps_count) {
			reward = this->best_human_capital > human_capital && 
				this->strategy->GetTotalHumanCapitalInvesting() > this->strategy->GetBudget() ? -1.5 : 0.0;
			this->is_new_best_value = false;
		}
		else {
			reward = 1.0;
			this->best_human_capital = human_capital;
			this->best_steps_count = this->steps_count;
			this->test1 = this->strategy->GetSalaryInvesting();
			this->test2 = this->strategy->GetEducationInvesting();
			this->test3 = this->strategy->GetHealthInvesting();
			this->test4 = this->strategy->GetCulturalInvesting();
			this->test5 = this->strategy->GetInformationInvesting();
			this->is_new_best_value = true;
		}
	}













	
	double max_value_for_current_state = current_state->GetMaxValue();
	double max_value_for_new_state = new_state->GetMaxValue();
	double new_value = max_value_for_current_state + 0.8 * 
		( reward + this->normalizationFactor * max_value_for_new_state - max_value_for_current_state);

	current_state->SetNewValue(this->index_of_best_action, new_value);

	
	
	

	if (is_end) {
		// 100 000 000
		if (this->global_loop > 100000) {
			this->global_loop = 0;
			this->global_count_coef++;


			this->strategy->PrintData(this->is_new_best_value, this->best_steps_count, this->best_human_capital, this->global_count_coef * 1000000, this->steps_count);
			//this->strategy->PrintData(this->is_new_best_value, this->best_steps_count, this->global_count_coef * 1000000, this->steps_count);
			std::cout << "-------\n"
				<< "Index_of_best_action:" << this->index_of_best_action << "\n"
				<< "Index_of_best_action:" << current_state->GetMaxValueIndex() << "\n"
				<< "Index_of_best_action:" << current_state->GetMaxValue() << "\n"

				<< "-------\n"

				<< "Salary:" << this->test1 << "\n"
				<< "Education:" << this->test2 << "\n"
				<< "Health:" << this->test3 << "\n"
				<< "Cultural:" << this->test4 << "\n"
				<< "Information:" << this->test5 << "\n"
				
				<< "-------\n";

			//current_state->PrintStatistics();
		}

		steps_count = 0;
		this->strategy->Reset();
		
	}

	return this->strategy;
}

double HumanCapitalLooper::GetIndexByStrategy()
{
	return this->strategy->CalculateHumanCapital();
}

