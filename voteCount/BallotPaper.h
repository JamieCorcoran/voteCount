#pragma once
#include "Candidate.h"
class BallotPaper
{
private:
public:
	string candidates[4];
	int preference[4];
	BallotPaper();
	~BallotPaper();
	void setPreference(int, string);
	string getPreference(int);
};

