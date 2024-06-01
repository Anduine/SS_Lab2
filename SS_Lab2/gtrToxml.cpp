#include <string>
#include <iostream>
#include <fstream>
#include <stack>
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
	std::stack<int> levels;
	bool closepers = false;
	std::ifstream inputf(nameinputfile);
	if (!inputf) {
		std::cerr << "Unable to open input file\n";
		return;
	}
	std::ofstream outputf(nameoutfile);
	if (!outputf) {
		std::cerr << "Unable to open output file\n";
		return;
	}

	char g;
	int counter{ 1 };

	while (inputf)
	{
		inputf >> g;
		if (g-48 != counter)
		{
			levels.push(counter);

		}
		if (g-48 > counter)
		{
			outputf << '\t';
			counter++;
		}

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
	}

	inputf.close();
	outputf.close();
};