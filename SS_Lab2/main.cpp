#include <iostream>
#include <fstream>
#include <Windows.h>
#include "gtrToxml.h"
#include "xmlTogtr.h"


using namespace std;

int main()
{
    parseGTR("tree.gtr");

	parseXML("treeout.xml");

	return 0;
}