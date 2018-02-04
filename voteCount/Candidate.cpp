#include "stdafx.h"
#include "Candidate.h"
#include <string>
using namespace std;

Candidate::Candidate(string newName, string newParty)
{
	name = newName;
	party = newParty;
}

Candidate::Candidate() {}
Candidate::~Candidate(){}

void Candidate::setName(string theName)
{
	name = theName;
}
void Candidate::setParty(string theParty)
{
	party = theParty;
}
string Candidate::getName()
{
	return name;
}
string Candidate::getParty()
{
	return party;
}
