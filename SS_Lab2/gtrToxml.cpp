#include <string>
#include <iostream>
#include <fstream>
#include "gtrToxml.h"

void parseGTR(std::string inputfile, std::string outfile)
{
	std::string buff;
	std::ifstream inputf(inputfile);
	if (!inputf) {
		std::cerr << "Unable to open input file\n";
		return;
	}
	std::ofstream outputf(outfile);
	if (!outputf) {
		std::cerr << "Unable to open output file\n";
		return;
	}

	while (inputf)
	{
		inputf >> buff;
		if (buff == "1")
		{
			inputf >> buff;
			if (buff == "NAME")
			{
				inputf >> buff;
				outputf << "<person NAME=\"" << buff << "\" ";
			}
			else
			{
				outputf << buff;
				inputf >> buff; 
				outputf << "=\"" << buff << "\" ";
			}

		}

	}

	inputf.close();
	outputf.close();
};