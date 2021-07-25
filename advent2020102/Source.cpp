#include <iostream>
#include <fstream>
#include <string>

/*
Advent of Code Day 2 2020:
This project reads from custom format text file a list of potential passwords and reads how many are viable.
*/

int main()
{

	int range1[1000];
	int range2[1000];
	char letter[1000];
	std::string password[1000];
	std::string empty[1000];
	int count = 0, listNum = 0, numCorrect = 0, numCheck = 0;
	int counter1 = 0;

	std::ifstream inputFile;
	inputFile.open("advent2020102.txt");

	if(!inputFile)
	{
		std::cout << "Error finding input file." << std::endl;
		system("pause");
		exit(-1);
	}

	while (!inputFile.eof())
	{
		inputFile >> range1[count] >> range2[count] >> letter[count] >> empty[count] >> password[count];
		//std::cout << range1[count] << " " << range2[count] << " " << letter[count] << " " << empty[count] << " " << password[count] << std::endl;
		count++;
	}

	listNum = count;

	for (int i = 0; i < listNum; i++)
	{
		range2[i] = range2[i] * -1;
		//std::cout << range2[i] << std::endl;

		//count number of characters in the password string
		for (int j = 0; j < password[i].length(); j++)
		{
			if (password[i][j] == letter[i])
			{
				numCheck++;
			}
		}

		//if the number of character is in between inclusively range1 and range2 add 1 to numCorrect;
		if (numCheck >= range1[i] && numCheck <= range2[i])
		{
			numCorrect++;
		}

		numCheck = 0;
	}

	std::cout << "Part 1: Number of viable passwords are: " << numCorrect << "." << std::endl;

	numCorrect = 0;

	//parse to first range number index and check the character, add 1 if there, parse to second range number index and check the character, add 1 if there
	for (int i = 0; i < listNum; i++)
	{
		//j is the index number of the string, range1 and 2 are the indices where the letters are to be checked
		for (int j = 0; j < password[i].length(); j++)
		{
			//if the index and range1 are same that means the index is correct one, index start from 0, range must compensate for that and so subtract 1
			if (j == (range1[i]-1))
			{
				//password[i][j] is character and if its the same character as letter[i] then add counter
				if (password[i][j] == letter[i])
				{
					counter1++;
				}
			}
			if (j == (range2[i]-1))
			{
				if (password[i][j] == letter[i])
				{
					counter1++;
				}
			}		
		}
		//if 1 then add number of correct, if 2 or 0 do nothing because invalid
		if (counter1 == 1)
		{
			numCorrect++;
		}
		counter1 = 0;
	}
	
	std::cout << "Part 2: Number of viable passwords are: " << numCorrect << "." << std::endl;

	return 0;
}