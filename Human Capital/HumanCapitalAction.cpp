#include "includes.h"

HumanCapitalAction::HumanCapitalAction(short budget, short salary, short education,
	short health, short cultural, short information)
{
	this->budget = budget;
	this->salary = salary;
	this->education = education;
	this->health = health;
	this->cultural = cultural;
	this->information = information;

}



void HumanCapitalAction::SetSalary(short salary)
{
	this->salary = salary;
}

void HumanCapitalAction::SetEducation(short education)
{
	this->education = education;
}

void HumanCapitalAction::SetHealth(short health)
{
	this->health = health;
}

void HumanCapitalAction::SetCultural(short cultural)
{
	this->cultural = cultural;
}

void HumanCapitalAction::SetInformation(short information)
{
	this->information = information;
}

short HumanCapitalAction::GetSalary()
{
	return this->salary;
}

short HumanCapitalAction::GetEducation()
{
	return this->education;
}

short HumanCapitalAction::GetHealth()
{
	return this->health;
}

short HumanCapitalAction::GetCultural()
{
	return this->cultural;
}

short HumanCapitalAction::GetInformation()
{
	return this->information;
}

double HumanCapitalAction::GetBudget()
{
	return this->budget;
}
