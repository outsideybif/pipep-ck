#pragma once
class HumanCapitalAction
{
public:
	HumanCapitalAction(short budget = 1000, short salary = 0, short education = 0,
		short health = 0, short cultural = 0,
		short information = 0);


	void SetSalary(short salary);
	void SetEducation(short education);
	void SetHealth(short health);
	void SetCultural(short cultural);
	void SetInformation(short information);

	short GetSalary();
	short GetEducation();
	short GetHealth();
	short GetCultural();
	short GetInformation();

	double GetBudget();


protected:
	short	budget = 1000,
		salary = 0,
		education = 0,
		health = 0,
		cultural = 0,
		information = 0;



};

