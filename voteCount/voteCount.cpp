// voteCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Candidate.h"
#include "BallotPaper.h"
using namespace std;

int main()
{
	int countRand = 0, countPref = 0, nextPref = 2, totalVotes = 0, totalCandResults = 0, votesToGive = 0;
	const int firstPref = 1;
	int i, j, first, temp, count = 0, randEl, countRound = 0, countAmountOfCand = 0, countAmountOfBallot = 0, amountOfBallots, i2, amountOfCand, i3, i4;
	string arrayInputs[200];
	vector<int> ballotVotes;
	vector<string> arrayInput;
	vector<Candidate> candidates;
	vector<BallotPaper> ballots;
	vector<int>candResults;

	ifstream vote{ "votes.txt" };
	if (!vote.is_open()) return -1;
	i = 0;
	while (!vote.eof())
	{
		vote >> arrayInputs[i];
		i++;
	}
	i = 0;
	while (arrayInputs[i] != "")
	{
		if (arrayInputs[i].length() >= 2)
		{
			int finish = arrayInputs[i].find(":");
			string name = arrayInputs[i].substr(0, finish);
			int start = arrayInputs[i].find(":");
			string candParty = arrayInputs[i].substr(start + 1);
			candidates.push_back(Candidate(name, candParty));
			countAmountOfCand++;
		}
		if (arrayInputs[i].length() == 1)
		{
			ballotVotes.push_back(stoi(arrayInputs[i]));
			countAmountOfBallot++;
		}
		i++;
	}
	i4 = candidates.size() - 1;
	count = 0;
	for (i = 0; i <= ballotVotes.size() - 1; i++)
	{
			if (ballotVotes[i] > candidates.size())
			{
				cout << "Please fix your text file" << endl;
				system("pause");
				return 0;
			}
			cout << i << ":" << ballotVotes[i]  << "     "<< i+1<< ":" << ballotVotes[i + 1] <<  endl;
			if (ballotVotes[i] == ballotVotes[i+1])
			{
				cout << "Please fix your text file" << endl;
				system("pause");
				return 0;
			}
			if (i == i4 - 1)
			{
				count++;
				i = count -1;
				if (count == i4)
				{
					i = count;
					i4 = (count + 1 + (candidates.size() - 1));
				}
			}
	}
	amountOfBallots = countAmountOfBallot / candidates.size();
	amountOfCand = candidates.size();
	for (i = 0; i <= amountOfBallots-1; i++)
	{
		ballots.push_back(BallotPaper());
	}
	i2 = 0;
	i = 0;
	for (j = 0; j < candidates.size()-1; j++)
	{
		while (i2 <= ballotVotes.size()-1)
		{
			ballots[i].setPreference(ballotVotes[i2], candidates[j].getName());
			i2 += candidates.size();
			i++;
			i4++;
		}
		amountOfCand--;
		i2 = candidates.size() - amountOfCand;
		i= 0;
	} 
	for (i = 0; i <= candidates.size() - 1; i++)
	{
		candResults.push_back(0);
	}
	for (i = 0; i < amountOfBallots; i++)
	{
		for (j = 0; j < countAmountOfCand; j++)
		{
			if (candidates[j].getName() == ballots[i].getPreference(1))
			{
				candResults[j] = 1 + candResults[j];
				totalVotes++;
			}
		}
	}
	for (i = candResults.size() - 1; i > 0; i--)
	{
		int first = 0, temp;
		string firstCand, firstParty, tempCand, tempParty;
		for (j = 1; j <= i; j++)
		{
			if (candResults[j] < candResults[first])
			{
				first = j;
				firstCand = candidates[j].getName();
				firstParty = candidates[j].getParty();
			}
			tempParty = candidates[first].getParty();
			tempCand = candidates[first].getName();
			temp = candResults[first];
			candidates[first].setParty(candidates[i].getParty());
			candidates[first].setName(candidates[i].getName());
			candResults[first] = candResults[i];
			candidates[i].setParty(tempParty);
			candidates[i].setName(tempCand);
			candResults[i] = temp;
		}
	}
	count = 0;
	while (count < candidates.size()-1)
	{
		int round = count;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "----------------------------" << (1 + count) << ": ROUND RESULTS----------------------------" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		if (countRand == 0)
		{
			for (i = 0; i <= candResults.size() - (1 + count); i++)
			{
				if (candResults[candResults.size() - (1 + count)] == candResults[i])
				{
					countRand++;
				}
			}
		}
		if (countRand > 1)
		{
			for (i = 0; i <= 6; i++)
			{
				randEl = rand() % (candidates.size() - (1 + count)) + (countRand - 1);
			}
			string tempCand, tempParty;
			temp;
			tempParty = candidates[randEl].getParty();
			tempCand = candidates[randEl].getName();
			temp = candResults[randEl];
			candidates[randEl].setParty(candidates[(candidates.size() - (1 + count))].getParty());
			candidates[randEl].setName(candidates[(candidates.size() - (1 + count))].getName());
			candResults[randEl] = candResults[(candidates.size() - (1 + count))];
			candidates[(candidates.size() - (1 + count))].setParty(tempParty);
			candidates[(candidates.size() - (1 + count))].setName(tempCand);
			candResults[(candidates.size() - (1 + count))] = temp;
			countRand = 0;
		}
		for (i = 0; i <= candidates.size() - (1 + count); i++)
		{
			cout << candidates[i].getName() << ", " << candidates[i].getParty() << endl;
			cout << candResults[i] << endl;
			if (i >= (candidates.size() - 1) - count)
			{
				if (count == candidates.size() - 2)
				{
					break;
				}
				if (candResults[candidates.size() - (count + 1)] != 0)
				{
					for (i2 = 0; i2 <= ballots.size() - 1; i2++)
					{
						if (ballots[i2].getPreference(firstPref) == candidates[(candidates.size() - 1) - count].getName())
						{
							for (j = 0; j <= candidates.size() - (count + 1); j++)
							{
								if (ballots[i2].getPreference(nextPref) == candidates[j].getName())
								{
									candResults[j] = candResults[j] + 1;
									countPref++;
									votesToGive++;
								}
							}
							if (countPref > candResults[candidates.size() - (count + 1)])
							{
								countPref--;
							}
							if (votesToGive >= candResults[candidates.size() - (count + 1)])
							{
								break;
							}
						}
						if (i2 == ballots.size() - 1)
						{
							if (countPref == candResults[candidates.size() - (count + 1)])
							{
								break;
							}
							else
							{
								nextPref++;
								i2 = 0;
							}
						}
					}
					votesToGive = 0;
					countPref = 0;
				}
				else
				{
					break;
				}
			}
		}
		cout << "-------------------------------------------------------------------------" << endl;
		cout << candidates[(candidates.size() - 1) - count].getName() << ", was eliminated with vote count : " << candResults[(candidates.size() - 1) - count] << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		count++;
		for (i = candResults.size() - 1; i > 0; i--)
		{
			int first = 0, temp;
			string firstCand, firstParty, tempCand, tempParty;
			for (j = 1; j <= i; j++)
			{
				if (candResults[j] < candResults[first])
				{
					first = j;
					firstCand = candidates[j].getName();
					firstParty = candidates[j].getParty();
				}
				tempParty = candidates[first].getParty();
				tempCand = candidates[first].getName();
				temp = candResults[first];
				candidates[first].setParty(candidates[i].getParty());
				candidates[first].setName(candidates[i].getName());
				candResults[first] = candResults[i];
				candidates[i].setParty(tempParty);
				candidates[i].setName(tempCand);
				candResults[i] = temp;
			}
		}
		system("pause");
	}
	cout << "THE WINNER IS : " << candidates[0].getName() << ", " << candidates[0].getParty() << ", WITH " << candResults[0] << " VOTES" << endl;
	system("pause");
	return 0;
}
