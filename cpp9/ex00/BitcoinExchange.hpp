#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef std::map<std::string, long> mymap;

void parse_data(char * file, std::ifstream& inputfile);

