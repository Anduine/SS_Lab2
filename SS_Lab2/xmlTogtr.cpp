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
		cerr << "Неможливо відкрити вхідний файл " << inputfile << '\n';
		return;
	}
	std::ofstream outputf(outfile);
	if (!outputf) {
		cerr << "Неможливо відкрити вихідний файл " << outfile << '\n';
		return;
	}

    int x = 1;

    while (inputf)
    {
        inputf >> buff;
        if (buff == "</person>") {
            break;
        }
        if (buff == "<person")
        {
            int a = x;
            while (a == x) {
                inputf >> buff;

                if (buff.find("surname") != -1) {
                    int pos = buff.find("\"");
                    buff.erase(0, pos + 1);
                    pos = buff.find("\"");
                    buff.erase(pos, 1);

                    outputf << x << " SURNAME " << buff << endl;
                }
                else if (buff.find("name") != -1) {
                    int pos = buff.find("\"");
                    buff.erase(0, pos + 1);
                    pos = buff.find("\"");
                    buff.erase(pos, 1);

                    outputf << x << " NAME " << buff << endl;
                }
                else if (buff.find("gender") != -1) {
                    int pos = buff.find("\"");
                    buff.erase(0, pos + 1);
                    pos = buff.find("\"");
                    buff.erase(pos, 1);

                    outputf << x << " GENDER " << buff << endl;
                }
                else if (buff.find("birthdate") != -1) {
                    int pos = buff.find("\"");
                    buff.erase(0, pos + 1);
                    pos = buff.find("\"");
                    buff.erase(pos, 2);

                    outputf << x++ << " BIRTHDATE " << buff << endl;
                }
            }
        }
    }

    inputf.close();
    outputf.close();
    std::cout << "Інформація записана із файлу " << inputfile << " у файл " << outfile << '\n';
};