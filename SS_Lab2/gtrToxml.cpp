#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "gtrToxml.h"

void lowercase(std::string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

void parseGTR(std::string nameinputfile, std::string nameoutfile)
{
	std::string buff;
	std::vector<int> levels;


	std::ifstream inputf(nameinputfile);
	if (!inputf) {
		std::cerr << "Unable to open input file " << nameinputfile << '\n';
		return;
	}
	std::ofstream outputf(nameoutfile);
	if (!outputf) {
		std::cerr << "Unable to open output file " << nameoutfile << '\n';
		return;
	}

	char g;
	int counter{ 0 };
	inputf >> g;
	if (g - 48 > counter)
	{
		levels.push_back(++counter);
	}


	while (inputf)
	{
			inputf >> buff;
			if (buff == "NAME")
			{
				inputf >> buff;
				outputf << "<person name=\"" << buff << "\" ";
			}
			else if (buff == "BIRTHDATE")
			{
				lowercase(buff);
				outputf << buff;
				inputf >> buff;
				outputf << "=\"" << buff << "\">\n";
			}
			else
			{
				lowercase(buff);
				outputf << buff;
				inputf >> buff; 
				outputf << "=\"" << buff << "\" ";
			}

			inputf >> g;
			if (g - 48 > counter)
			{
				levels.push_back(++counter);
				for (int j = 0; j < levels[counter - 1] - 1; j++)
				{
					outputf << '\t';
				}
			}
	}

	for (int i = levels.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < levels[i]-1; j++)
		{
			outputf << '\t';
		}
		outputf << "</person>\n";
	}

	inputf.close();
	outputf.close();
	std::cout << "Information is written from a file " << nameinputfile << " to  file " << nameoutfile << '\n';
};