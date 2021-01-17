#pragma once
#include "HumanCapitalAction.h"

class HumanCapitalStrategy
{

public:
	HumanCapitalStrategy(short budget = 1000, short creativity = 0, short competence = 0,
		short purposefulness = 0, short communicativeness = 0,
		short motivation = 0);


	void SetCreativity(short creativity);
	void SetCompetence(short competence);
	void SetPurposefulness(short purposefulness);
	void SetCommunicativeness(short communicativeness);
	void SetMotivation(short motivation);

	void AddCreativity(short creativity);
	void AddCompetence(short competence);
	void AddPurposefulness(short purposefulness);
	void AddCommunicativeness(short communicativeness);
	void AddMotivation(short motivation);

	short GetCreativity();
	short GetCompetence();
	short GetPurposefulness();
	short GetCommunicativeness();
	short GetMotivation();

	void ApplyAction(HumanCapitalAction* action);

	void PrintData();

	void Reset();


protected:
	short	budget = 1000,
		creativity = 0,
		competence = 0,
		purposefulness = 0,
		communicativeness = 0,
		motivation = 0;

	short	start_budget = 1000,
		start_creativity = 0,
		start_competence = 0,
		start_purposefulness = 0,
		start_communicativeness = 0,
		start_motivation = 0;



private:

};

