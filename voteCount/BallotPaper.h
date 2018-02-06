#pragma once
#include "Candidate.h"
class BallotPaper
{
private:
public:
	string candidates[100];
	int preference[100];
	BallotPaper();
	~BallotPaper();
	void setPreference(int, string);
	string getPreference(int);
};

