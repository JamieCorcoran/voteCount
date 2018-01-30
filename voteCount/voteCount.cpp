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
	const int amountOfCand = 4, amountOfBallot = 8;
	int cand1 = 0, cand2 = 0, cand3 = 0, cand4 = 0;
	int arrayinputVotes[amountOfBallot][amountOfCand];
	int i, j, first, temp, count = 0, randEl;
	string candResults1, candResults2, candResults3, candResults4;
	Candidate c1, c2, c3, c4;
	BallotPaper b1, b2, b3, b4, b5, b6, b7, b8;
	Candidate arrayCand[amountOfCand] = { c1, c2, c3, c4 };
	c1.setName("John"), c2.setName("Tom"), c3.setName("Sam"), c4.setName("Aoife");
	c1.setParty("FiannaFail"), c2.setParty("SinnFein"), c3.setParty("Labour"), c4.setParty("FineGael");

	ifstream vote { "votes.txt" };
	if (!vote.is_open()) return -1;
	for (i = 0; i < amountOfBallot; ++i)
	{
		for (j = 0; j < amountOfCand; ++j)
		{
			vote >> arrayinputVotes[i][j];
		}
	}
	vote.close();
	for (i = 0; i < amountOfBallot; i++)
	{
		for (j = 0; j < amountOfCand; j++)
		{
			arrayinputVotes[i][j] = int(arrayinputVotes[i][j]);
			cout << arrayinputVotes[i][j];
		}
		cout << endl;
	}
	for (i = 0; i < amountOfBallot; i++)
	{
		for (j = 0; j < amountOfCand; j++)
		{
			switch (i) 
			{
				case 0:
					switch (j)
					{
						case 0: b1.setPreference(arrayinputVotes[i][j], c1.getName());
							break;
						case 1: b1.setPreference(arrayinputVotes[i][j], c2.getName());
							break;
						case 2: b1.setPreference(arrayinputVotes[i][j], c3.getName());
							break;
						case 3: b1.setPreference(arrayinputVotes[i][j], c4.getName());
							break;
					};
				case 1: 
					switch (j)
					{
					case 0: b2.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b2.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b2.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b2.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 2: 
					switch (j)
					{
					case 0: b3.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b3.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b3.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b3.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 3: 
					switch (j)
					{
					case 0: b4.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b4.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b4.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b4.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 4: 
					switch (j)
					{
					case 0: b5.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b5.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b5.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b5.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 5:
					switch (j)
					{
					case 0: b6.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b6.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b6.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b6.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 6: 
					switch (j)
					{
					case 0: b7.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b7.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b7.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b7.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
				case 7: 
					switch (j)
					{
					case 0: b8.setPreference(arrayinputVotes[i][j], c1.getName());
						break;
					case 1: b8.setPreference(arrayinputVotes[i][j], c2.getName());
						break;
					case 2: b8.setPreference(arrayinputVotes[i][j], c3.getName());
						break;
					case 3: b8.setPreference(arrayinputVotes[i][j], c4.getName());
						break;
					};
			}
		}
	}
	BallotPaper ballotVotes[amountOfBallot] = { b1, b2, b3, b4, b5, b6, b7, b8 };
	cout << "FIRST ROUND COUNTING" << endl;
	system("pause");
	for (i = 0; i < amountOfBallot; i++)
	{
		if (ballotVotes[i].getPreference(1) == "John")
		{
			cand1 += 1;
		}
		else if (ballotVotes[i].getPreference(1) == "Tom")
		{
			cand2 += 1;
		}
		else if (ballotVotes[i].getPreference(1) == "Sam")
		{
			cand3 += 1;
		}
		else if (ballotVotes[i].getPreference(1) == "Aoife")
		{
			cand4 += 1;
		}
	}
	candResults1 = c1.getName() + " : " + char((cand1)+48);
	candResults2 = c2.getName() + " : " + char((cand2)+48);
	candResults3 = c3.getName() + " : " + char((cand3)+48);
	candResults4 = c4.getName() + " : " + char((cand4)+48);
	string countResults[amountOfCand] = { candResults1, candResults2, candResults3, candResults4};
	cout << "FIRST ROUND RESULTS" << endl;
	for (int i = 0; i < amountOfCand; i++)
	{
		for (int j = i + 1; j < amountOfCand; j++)
		{
			if (int(countResults[i].back() - 48) > int(countResults[j].back() - 48))
			{
				string temp = countResults[i];
				countResults[i] = countResults[j];
				countResults[j] = temp;
			}
		}
	}
	for (i = 0; i < amountOfCand; i++)
	{
		cout << countResults[i] << endl;
	}
	for (i = 1; i < amountOfCand; i++)
	{
		if (int(countResults[0].back() - 48) == int(countResults[i].back() - 48))
		{
			count++;
		}
	}
	if (count > 0)
	{
		for (i = 0; i < amountOfCand; i++)
		{

		}
	}
	else
	{
		for(i = 0; i < amountOfCand; i++)
		{

		}
	}

	/*system("pause");
	cout << "SECOND ROUND COUNTING" << endl;
	system("pause");
	cout << "SECOND ROUND RESULTS" << endl;
	for (i = 0; i < amountOfCand; i++)
	{
		cout << countResults[i] << endl;
	}*/
	system("pause");
    return 0;
}

