#include "includes.h"

HumanCapitalStrategy::HumanCapitalStrategy(double budget, double creativity, double competence, double purposefulness, 
	double communicativeness, double motivation)
{
	this->budget = budget;
	this->SetCreativity(creativity);
	this->SetCommunicativeness(communicativeness);
	this->SetCompetence(competence);
	this->SetMotivation(motivation);
	this->SetPurposefulness(purposefulness);

	this->start_budget = budget;
	this->start_creativity = creativity;
	this->start_competence = competence;
	this->start_purposefulness = purposefulness;
	this->start_communicativeness = communicativeness;
	this->start_motivation = motivation;
}

void HumanCapitalStrategy::SetCreativity(double creativity)
{
	this->creativity = creativity;
}

void HumanCapitalStrategy::SetCompetence(double competence)
{
	this->competence = competence;
}

void HumanCapitalStrategy::SetPurposefulness(double purposefulness)
{
	this->purposefulness = purposefulness;
}

void HumanCapitalStrategy::SetCommunicativeness(double communicativeness)
{
	this->communicativeness = communicativeness;
}

void HumanCapitalStrategy::SetMotivation(double motivation)
{
	this->motivation = motivation;
}

void HumanCapitalStrategy::AddSalary(double salary)
{
	this->salary_investing += salary;
	this->UpdateSalaryInvesting();
}

void HumanCapitalStrategy::AddEducation(double education)
{
	this->education_capital_investing += education;
	this->UpdateEducationInvesting();
}

void HumanCapitalStrategy::AddHealth(double health)
{
	this->health_capital_investing += health;
	this->UpdateHealthInvesting();
}

void HumanCapitalStrategy::AddCultural(double cultural)
{
	this->cultural_capital_investing += cultural;
	this->UpdateCulturalInvesting();
}

void HumanCapitalStrategy::AddInformation(double information)
{
	this->information_capital_investing += information;
	this->UpdateInfromationInvesting();
}

double HumanCapitalStrategy::GetSalaryInvesting()
{
	return this->salary_investing;
}

double HumanCapitalStrategy::GetEducationInvesting()
{
	return this->education_capital_investing;
}

double HumanCapitalStrategy::GetHealthInvesting()
{
	return this->health_capital_investing;
}

double HumanCapitalStrategy::GetCulturalInvesting()
{
	return this->cultural_capital_investing;
}

double HumanCapitalStrategy::GetInformationInvesting()
{
	return this->information_capital_investing;
}

double HumanCapitalStrategy::GetBudget()
{
	return this->budget;
}

double HumanCapitalStrategy::GetTotalHumanCapitalInvesting()
{
	return this->human_capital_investing;
}

double HumanCapitalStrategy::GetHumanCapital()
{
	return this->human_capital;
}

double HumanCapitalStrategy::GetCreativity()
{
	return this->creativity;
}

double HumanCapitalStrategy::GetCompetence()
{
	return this->competence;
}

double HumanCapitalStrategy::GetPurposefulness()
{
	return this->purposefulness;
}

double HumanCapitalStrategy::GetCommunicativeness()
{
	return this->communicativeness;
}

double HumanCapitalStrategy::GetMotivation()
{
	return this->motivation;
}

double HumanCapitalStrategy::CalculateHumanCapital()
{
	return round(
		
		(this->salary * this->competence * 0.2 +
		this->education_capital * this->creativity * 0.25+
		this->health_capital * this->motivation * 0.18 +
		this->cultural_capital * this->purposefulness * 0.15 +
		this->information_capital * this->communicativeness * 0.23) * this->human_capital_investing * 10000
	
	) / 10000;

}

void HumanCapitalStrategy::ApplyAction(HumanCapitalAction* action)
{
	
	//this->budget += action->GetBudget();

	this->AddSalary(action->GetSalary());
	this->AddEducation(action->GetEducation());
	this->AddHealth(action->GetHealth());
	this->AddCultural(action->GetCultural());
	this->AddInformation(action->GetInformation());
}

void HumanCapitalStrategy::PrintData(bool is_new_best_value, int best_counts, int  best_human_capital, int global_loop, int current_steps )
{
	system("cls");
	std::cout << "Loop:" << global_loop << " | "
		<< "Total:" << this->CalculateHumanCapital() << " | "
		<< "Best HC:" << best_human_capital << " | "
		<< "Best counts:" << best_counts << " | "
		<< "Current steps:" << current_steps << "\n"
		<< "-------\n"
		<< "Salary:" << this->salary << "\n"
		<< "Education:" << this->education_capital << "\n"
		<< "Health:" << this->health_capital << "\n"
		<< "Cultural:" << this->cultural_capital << "\n"
		<< "Information:" << this->information_capital << "\n"
		<< "-------\n"
		<< "Salary investing:" << this->salary_investing << "\n"
		<< "Education  investing:" << this->education_capital_investing << "\n"
		<< "Health  investing:" << this->health_capital_investing << "\n"
		<< "Cultural  investing:" << this->cultural_capital_investing << "\n"
		<< "Information  investing:" << this->information_capital_investing << "\n";
}

void HumanCapitalStrategy::Reset()
{
	this->budget = start_budget;
	this->SetCreativity(start_creativity);
	this->SetCommunicativeness(start_communicativeness);
	this->SetCompetence(start_competence);
	this->SetMotivation(start_motivation);
	this->SetPurposefulness(start_purposefulness);

	this->human_capital = 0;
	this->human_capital_investing = 0;

	this->salary_investing = 0;
	this->education_capital_investing = 0;
	this->health_capital_investing = 0;
	this->cultural_capital_investing = 0;
	this->information_capital_investing = 0;

	this->salary = 0;
	this->education_capital = 0;
	this->health_capital = 0;
	this->cultural_capital = 0;
	this->information_capital = 0;
}

void HumanCapitalStrategy::UpdateTotalHumanCapitalInvesting()
{
	this->human_capital_investing = this->salary_investing +
		this->education_capital_investing +
		this->health_capital_investing +
		this->cultural_capital_investing +
		this->information_capital_investing;
	//this->human_capital_investing = 1;
}

void HumanCapitalStrategy::UpdateSalaryInvesting()
{
	this->UpdateTotalHumanCapitalInvesting();
	if (this->human_capital_investing == 0) {
		return;
	}
	this->salary = this->salary_investing / this->human_capital_investing;
}

void HumanCapitalStrategy::UpdateEducationInvesting()
{
	this->UpdateTotalHumanCapitalInvesting();
	if (this->human_capital_investing == 0) {
		return;
	}
	this->education_capital = this->education_capital_investing / this->human_capital_investing;
}

void HumanCapitalStrategy::UpdateHealthInvesting()
{
	this->UpdateTotalHumanCapitalInvesting();
	if (this->human_capital_investing == 0) {
		return;
	}
	this->health_capital = this->health_capital_investing / this->human_capital_investing;
}

void HumanCapitalStrategy::UpdateCulturalInvesting()
{
	this->UpdateTotalHumanCapitalInvesting();
	if (this->human_capital_investing == 0) {
		return;
	}
	this->cultural_capital = this->cultural_capital_investing / this->human_capital_investing;
}

void HumanCapitalStrategy::UpdateInfromationInvesting()
{
	this->UpdateTotalHumanCapitalInvesting();
	if (this->human_capital_investing == 0) {
		return;
	}
	this->information_capital = this->information_capital_investing / this->human_capital_investing;
}
