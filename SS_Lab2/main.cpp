#include <iostream>
#include <fstream>
#include <Windows.h>
#include "gtrToxml.h"
#include "xmlTogtr.h"


using namespace std;

int main()
{
    parseGTR("tree.gtr");  // name of inputfile

	parseXML("treeout.gtr", "treeout.xml");  // name of outputfile

	return 0;
}