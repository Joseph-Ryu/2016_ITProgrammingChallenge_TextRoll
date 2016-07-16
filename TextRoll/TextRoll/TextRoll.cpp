/*
	Joseph Ryu
	Text Roll Problem
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	//declare and initialize ifstream object
	ifstream inFile(argv[1]);
	
	int lineCounter = 0; //max 100
	int currLine = 1;
	string line; //stores each line
	char ch; 
	int column; //this holds the column value
	int dropCol=0; //this holds the dropping column value
	bool noSpace;

	//get total lines first, validate the length of each line (100 max)
	while (getline(inFile, line))
	{
		lineCounter++;
		if (line.length() > 100)
		{
			cerr << "One of the line(s) are too long. You can only have up to 100 characters per line\n";
			return EXIT_FAILURE;
		}	
	}
	inFile.close();

	//reload and analyze the text
	inFile.open(argv[1]);
	//run loop and check each line
	//first see if the line is the last line
	while(getline(inFile, line))
	{
		noSpace = true; //reset each line
		if (dropCol >= line.length())
		{
			column = dropCol + 1;
			break;
		}
		//if last line
		if (currLine == lineCounter)
		{
			//1. if ' ', its length is the col value
			for (int i = dropCol; i < line.length(); i++)
			{
				if (line[i] == ' ')
				{
					column = i + 1;
					noSpace = false;
					break;
				}

			}//end for
			//2. if no space in the last line, then its length is the col value
			if (noSpace == true)
				column = line.length();

		}//end if last line
		
		//if not last line
		else
		{
			//1. if space found
			for (int i = dropCol; i < line.length(); i++)
			{
				if (line[i] == ' ')
				{
					column = i + 1;
					noSpace = false;
					dropCol = i;
					break;
				}

			}//end for
			//2. if no space
			if (noSpace == true)
				dropCol = line.length();

		}

		currLine++; 
	}

	cout << "Ball landed on column: " << column << endl;

}//end main