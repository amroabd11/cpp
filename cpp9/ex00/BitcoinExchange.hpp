#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef std::map<std::string, double> mymap;

void process_data(std::ifstream&, mymap&);
void parse_csv(mymap&);

