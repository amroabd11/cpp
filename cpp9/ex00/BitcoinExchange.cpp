#include "BitcoiExchange.hpp"

void parse_data(char* file, std::ifstream& inputfile)
{
	if (!file)
		throw std::runtime_error("Error: could not open file.");
	inputfile.open(file);
	if (!inputfile.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(inputfile, line);
	if (line != "date | value")
		throw std::runtime_error("first line must be 'date | value'");
	while(getline(inputfile,line))
	{

	}
}
