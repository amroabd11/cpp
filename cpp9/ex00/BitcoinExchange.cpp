#include "BitcoinExchange.hpp"

void parse_data(std::ifstream& inputfile, mymap& inputmap, char delim)
{
	if (!inputfile.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(inputfile, line);
	if (line != "date | value" || line != "date,exchange_rate")
		throw std::runtime_error("header is wrong");
	//std::stringstream token;
	while(getline(inputfile,line))
	{
		std::stringstream token(line); 
		std::string date;
		std::string delim;
		std::string value;
		token >> date >> delim >> value;

		std::cout << date <<", "<<delim<<", " <<value<<std::endl;
		// TODO i should not quite if one of them isn't present but i should print error;

		inputmap[date] = value;
	}
}
