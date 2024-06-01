#include <string>
#include <iostream>
#include <fstream>
#include "xmlTogtr.h"

using namespace std;

void parseXML(string outfile, string inputfile)
{
	string buff;
	ifstream inputf(inputfile);
	if (!inputf) {
		cerr << "Unable to open input file\n";
		return;
	}
	std::ofstream outputf(outfile);
	if (!outputf) {
		cerr << "Unable to open output file\n";
		return;
	}

    int x = 1;

    while (inputf)
    {
        //inputf >> ws;
        inputf >> buff;
        if (buff == "</person>") {
            break;
        }
        if (buff == "<person")
        {
            inputf >> buff;

            if (buff.find("name"))
            {
                int pos = buff.find("\"");
                buff.erase(0, pos + 1);
                pos = buff.find("\"");
                buff.erase(pos, 1);

                inputf >> buff;
                outputf << x << " NAME " << buff;
            }
            else if (buff.find("surname"))
            {
                int pos = buff.find("\"");
                buff.erase(0, pos + 1);
                pos = buff.find("\"");
                buff.erase(pos, 1);

                inputf >> buff;
                outputf << x << " SURNAME " << buff;
            }
            else if (buff.find("gender"))
            {
                int pos = buff.find("\"");
                buff.erase(0, pos + 1);
                pos = buff.find("\"");
                buff.erase(pos, 1);

                inputf >> buff;
                outputf << x << " GENDER " << buff;
            }
            else if (buff.find("birthdate"))
            {
                int pos = buff.find("\"");
                buff.erase(0, pos + 1);
                pos = buff.find("\"");
                buff.erase(pos, 2);

                inputf >> buff;
                outputf << x++ << " BIRTHDATE " << buff;
            }
        }
    }

    inputf.close();
    outputf.close();
};