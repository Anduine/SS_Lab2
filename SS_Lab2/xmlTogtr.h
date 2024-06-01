#pragma once
#include <string>

using namespace std;

struct Person2 {
    string name;
    string surname;
    string gender;
    string birthdate;
};

void parseXML(string outfile, string inputfile = "E:\\Univer\\SS_GDtaK\\sr2\\program\\SS_Lab2\\tree.xml");