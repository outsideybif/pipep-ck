#include "includes.h"

HumanCapitalAction::HumanCapitalAction(short budget, short creativity, short competence,
	short purposefulness, short communicativeness, short motivation)
{
	this->budget = budget;
	this->communicativeness = communicativeness;
	this->creativity = creativity;
	this->competence = competence;
	this->motivation = motivation;
	this->purposefulness = purposefulness;

}

void HumanCapitalAction::SetCreativity(short creativity)
{
	this->creativity = creativity;
}

void HumanCapitalAction::SetCompetence(short competence)
{
	this->competence = competence;
}

void HumanCapitalAction::SetPurposefulness(short purposefulness)
{
	this->purposefulness = purposefulness;
}

void HumanCapitalAction::SetCommunicativeness(short communicativeness)
{
	this->communicativeness = communicativeness;
}

void HumanCapitalAction::SetMotivation(short motivation)
{
	this->motivation = motivation;
}

short HumanCapitalAction::GetCreativity()
{
	return this->creativity;
}

short HumanCapitalAction::GetCompetence()
{
	return this->competence;
}

short HumanCapitalAction::GetPurposefulness()
{
	return this->purposefulness;
}

short HumanCapitalAction::GetCommunicativeness()
{
	return this->communicativeness;
}

short HumanCapitalAction::GetMotivation()
{
	return this->motivation;
}
