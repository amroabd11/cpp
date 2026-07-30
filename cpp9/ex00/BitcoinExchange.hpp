#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef std::map<std::string, std::string> mymap;

void parse_data(std::ifstream&, mymap&, char);

