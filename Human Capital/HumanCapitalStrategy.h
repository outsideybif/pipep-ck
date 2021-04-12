#pragma once
#include "HumanCapitalAction.h"

class HumanCapitalStrategy
{

public:
	HumanCapitalStrategy(double budget = 1000, double creativity = 0, double competence = 0,
		double purposefulness = 0, double communicativeness = 0,
		double motivation = 0);


	void SetCreativity(double creativity);
	void SetCompetence(double competence);
	void SetPurposefulness(double purposefulness);
	void SetCommunicativeness(double communicativeness);
	void SetMotivation(double motivation);

	void AddSalary(double salary);
	void AddEducation(double education);
	void AddHealth(double health);
	void AddCultural(double cultural);
	void AddInformation(double information);


	double GetSalaryInvesting();
	double GetEducationInvesting();
	double GetHealthInvesting();
	double GetCulturalInvesting();
	double GetInformationInvesting();


	double GetBudget();
	double GetTotalHumanCapitalInvesting();
	double GetHumanCapital();

	double GetCreativity();
	double GetCompetence();
	double GetPurposefulness();
	double GetCommunicativeness();
	double GetMotivation();

	double CalculateHumanCapital();

	void ApplyAction(HumanCapitalAction* action);

	void PrintData(bool is_new_best_value, int best_counts, int  best_human_capital, int global_loop, int current_steps);

	void Reset();


protected:
	double human_capital = 0;
	double human_capital_investing = 0;


	double	salary_investing = 0,
		education_capital_investing = 0,
		health_capital_investing = 0,
		cultural_capital_investing = 0,
		information_capital_investing = 0;

	double	salary = 0,
		education_capital = 0,
		health_capital = 0,
		cultural_capital = 0,
		information_capital = 0;

	double	budget = 1000,
		creativity = 0,
		competence = 0,
		purposefulness = 0,
		communicativeness = 0,
		motivation = 0;

	double	start_budget = 1000,
		start_creativity = 0,
		start_competence = 0,
		start_purposefulness = 0,
		start_communicativeness = 0,
		start_motivation = 0;



private:
	void UpdateTotalHumanCapitalInvesting();

	void UpdateSalaryInvesting();
	void UpdateEducationInvesting();
	void UpdateHealthInvesting();
	void UpdateCulturalInvesting();
	void UpdateInfromationInvesting();

};

