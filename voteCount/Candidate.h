#pragma once
#include <string>
using namespace std;
class Candidate
{
private:
	string name;
	string party;
public:
	Candidate();
	~Candidate();
	void setName(string);
	void setParty(string);
	string getName();
	string getParty();
};

