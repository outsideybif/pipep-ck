#pragma once
class HumanCapitalAction
{
public:
	HumanCapitalAction(short budget = 1000, short creativity = 0, short competence = 0,
		short purposefulness = 0, short communicativeness = 0,
		short motivation = 0);


	void SetCreativity(short creativity);
	void SetCompetence(short competence);
	void SetPurposefulness(short purposefulness);
	void SetCommunicativeness(short communicativeness);
	void SetMotivation(short motivation);

	short GetCreativity();
	short GetCompetence();
	short GetPurposefulness();
	short GetCommunicativeness();
	short GetMotivation();


protected:
	short	budget = 1000,
			creativity = 0,
			competence = 0,
			purposefulness = 0,
			communicativeness = 0,
			motivation = 0;



};

