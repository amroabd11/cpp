#include "BitcoiExchange.hpp"

void parse_data(std::ifstream& filefd, char* file)
{
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	filefd.open(file);
	if (filefd <0)
		throw std::runtime_error("Error: could not open file.");
}
