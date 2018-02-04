#include "stdafx.h"
#include "Candidate.h"
#include "BallotPaper.h"

BallotPaper::BallotPaper()
{
	
}

BallotPaper::~BallotPaper()
{
}

void BallotPaper::setPreference(int thePreference, string theCandidate)
{
	preference[thePreference -1] = thePreference;
	candidates[thePreference -1] = theCandidate;
}
string BallotPaper::getPreference(int num)
{
	return candidates[num-1];
}
