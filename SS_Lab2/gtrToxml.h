#pragma once

struct Person {
    std::string name;
    std::string surname;
    std::string gender;
    std::string birthdate;
};

void parseGTR(std::string inputfile, std::string outfile = "treeout.xml");