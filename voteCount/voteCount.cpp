// voteCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int countA(int votes[10][4])
{
	int i;
	int countVote = 0;

	for (i = 0; i < 10; i++)
	{
		if (votes[i][0] == 1)
		{
			countVote++;
		}
	}
	return countVote;
}
int countB(int votes[10][4])
{
	int i;
	int countVote = 0;

	for (i = 0; i < 10; i++)
	{
		if (votes[i][1] == 1)
		{
			countVote++;
		}
	}
	return countVote;
}
int  countC(int votes[10][4])
{
	int i;
	int countVote = 0;

	for (i = 0; i < 10; i++)
	{
		if (votes[i][2] == 1)
		{
			countVote++;
		}
	}
	return countVote;
}
int countD(int votes[10][4])
{
	int i;
	int countVote = 0;

	for (i = 0; i < 10; i++)
	{
		if (votes[i][3] == 1)
		{
			countVote++;
		}
	}
	return countVote;
}

int main()
{
	char arrayinput[100];
	char arrayCand[4] = {'A', 'B', 'C', 'D'};
	int index = 0;
	int arrayinputVotes[10][4];
	int arrayCountVotes[4];
	ifstream votes;
	int countPrint = 0;
	int i, j;
	int count = 0;
	int smallestVote, indexOfSmallVote;


	votes.open("votes.txt");
	votes >> arrayinput;
	votes.close();

	for (i = 0; i < 10; i++)
	{		
		for (j = 0; j < 4; j++)
		{
			arrayinputVotes[i][j] = (int)arrayinput[index] - 48;
			index++;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
		{
			cout << arrayinputVotes[i][j];
		}
		cout << endl;
	}

	arrayCountVotes[0] = countA(arrayinputVotes);
	arrayCountVotes[1] = countB(arrayinputVotes);
	arrayCountVotes[2] = countC(arrayinputVotes);
	arrayCountVotes[3] = countD(arrayinputVotes);
	while (count < 4)
	{
		if (count == 0)
		{
			cout << " First Round " << endl;
			for (i = 0; i < 4; i++)
			{
				cout << arrayCand[i] << "---";
			}
			cout << endl;
			for (i = 0; i < 4; i++)
			{
				cout << arrayCountVotes[i] << "---";
			}
			cout << endl;
			smallestVote = arrayCountVotes[0];
			for (i = 0; i < 4; i++)
			{
					if (arrayCountVotes[i] < smallestVote)
					{
						smallestVote = arrayCountVotes[i];
						indexOfSmallVote = i;
					}
			}
			cout << arrayCand[indexOfSmallVote] << " : Had the least votes" << endl;
			arrayCand[indexOfSmallVote] = ' ';
			for (i = indexOfSmallVote; i < 3; i++)
			{
				arrayCand[i] = arrayCand[i + 1];
			}
			arrayCand[3] = ' ';

		}
		if (count == 2)
		{
			cout << " Second Round " << endl;
			for (i = 0; i < 4; i++)
			{
				cout << arrayCand[i] << "---";
			}
			cout << endl;
			for (i = 0; i < 4; i++)
			{
				cout << arrayCountVotes[i] << "---";
			}
			cout << endl;
		}

		count++;
	}
	system("pause");
    return 0;
}

