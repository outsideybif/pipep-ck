#include "includes.h"

HumanCapitalStrategy::HumanCapitalStrategy(short budget, short creativity, short competence, short purposefulness, 
	short communicativeness, short motivation)
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

void HumanCapitalStrategy::SetCreativity(short creativity)
{
	this->creativity = creativity;
	if (this->creativity < 160) {
		this->creativity = 160;
	}
	if (this->creativity > 290) {
		this->creativity = 280;
	}
}

void HumanCapitalStrategy::SetCompetence(short competence)
{
	this->competence = competence;
	if (this->competence < 160) {
		this->competence = 160;
	}
	if (this->competence > 290) {
		this->competence = 280;
	}
}

void HumanCapitalStrategy::SetPurposefulness(short purposefulness)
{
	this->purposefulness = purposefulness;
	if (this->purposefulness < 160) {
		this->purposefulness = 160;
	}
	if (this->purposefulness > 290) {
		this->purposefulness = 280;
	}
}

void HumanCapitalStrategy::SetCommunicativeness(short communicativeness)
{
	this->communicativeness = communicativeness;
	if (this->communicativeness < 160) {
		this->communicativeness = 160;
	}
	if (this->communicativeness > 290) {
		this->communicativeness = 280;
	}
}

void HumanCapitalStrategy::SetMotivation(short motivation)
{
	this->motivation = motivation;
	if (this->motivation < 160) {
		this->motivation = 160;
	}
	if (this->motivation > 290) {
		this->motivation = 280;
	}
}

void HumanCapitalStrategy::AddCreativity(short creativity)
{
	this->creativity += creativity;
	if (this->creativity < 160) {
		this->creativity = 160;
	}
	if (this->creativity > 290) {
		this->creativity = 280;
	}
}

void HumanCapitalStrategy::AddCompetence(short competence)
{
	this->competence += competence;
	if (this->competence < 160) {
		this->competence = 160;
	}
	if (this->competence > 290) {
		this->competence = 280;
	}
}

void HumanCapitalStrategy::AddPurposefulness(short purposefulness)
{
	this->purposefulness += purposefulness;
	if (this->purposefulness < 160) {
		this->purposefulness = 160;
	}
	if (this->purposefulness > 290) {
		this->purposefulness = 280;
	}
}

void HumanCapitalStrategy::AddCommunicativeness(short communicativeness)
{
	this->communicativeness += communicativeness;
	if (this->communicativeness < 160) {
		this->communicativeness = 160;
	}
	if (this->communicativeness > 290) {
		this->communicativeness = 280;
	}
}

void HumanCapitalStrategy::AddMotivation(short motivation)
{
	this->motivation += motivation;
	if (this->motivation < 160) {
		this->motivation = 160;
	}
	if (this->motivation > 290) {
		this->motivation = 280;
	}
}

short HumanCapitalStrategy::GetCreativity()
{
	return this->creativity;
}

short HumanCapitalStrategy::GetCompetence()
{
	return this->competence;
}

short HumanCapitalStrategy::GetPurposefulness()
{
	return this->purposefulness;
}

short HumanCapitalStrategy::GetCommunicativeness()
{
	return this->communicativeness;
}

short HumanCapitalStrategy::GetMotivation()
{
	return this->motivation;
}

void HumanCapitalStrategy::ApplyAction(HumanCapitalAction* action)
{
	this->AddCommunicativeness(action->GetCommunicativeness());
	this->AddCompetence(action->GetCompetence());
	this->AddCreativity(action->GetCreativity());
	this->AddMotivation(action->GetMotivation());
	this->AddPurposefulness(action->GetPurposefulness());
}

void HumanCapitalStrategy::PrintData()
{
	system("cls");
	std::cout << "Creativity:" << this->GetCreativity() << "\n";
	std::cout << "Competence:" << this->GetCompetence() << "\n";
	std::cout << "Purposefulness:" << this->GetPurposefulness() << "\n";
	std::cout << "Communicativeness:" << this->GetCommunicativeness() << "\n";
	std::cout << "Motivation:" << this->GetMotivation() << "\n";
}

void HumanCapitalStrategy::Reset()
{
	this->budget = start_budget;
	this->SetCreativity(start_creativity);
	this->SetCommunicativeness(start_communicativeness);
	this->SetCompetence(start_competence);
	this->SetMotivation(start_motivation);
	this->SetPurposefulness(start_purposefulness);
}
