// voteCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	char arrayinput[100];
	int index = 0;
	int arrayinputVotes[100][4];
	ifstream votes;
	int countPrint = 0;
	int i, j;


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


	system("pause");
    return 0;
}

