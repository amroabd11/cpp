#include "BitcoinExchange.hpp"


bool ValidDate(std::string date)
{
	if (date.length() != 10)
		return false;
	size_t pos = date.find('-');
	std::string year;
	std::string month;
	std::string day;

	for (int i=0; i<date.length(); i++)
	{
		if( i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
}

void parse_csv(mymap& dbmap)
{
	std::ifstream db("data.csv");
	if (!db.is_open())
		throw std::runtime_error("Error: could not open csv file");
	std::string line;
	std::getline(db, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: wrong header");
	while(getline(db, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string:npos)
			continue;
		std::string date = line.substr(0,pos);
		std::string value = line.substr(pos+1);
		if (!ValidDate(date))
			continue;
		char *end; 
		double num = std::strtod(value.c_str(), &end);
		if (*end != '\0' || value.empty())
			continue;
		dbmap[date] = num;
	}

}

bool ValidValue(std::string value, double& val)
{
	char* end;
	val = std::strtod(value.c_str(), &end);
	if( *end!='\0' || value.empty())
		return false;
	return true;
}


void process_data(std::ifstream& inputfile, mymap& dbmap)
{
	if (!inputfile.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	std::getline(inputfile, line);
	if (line != "date | value")
		throw std::runtime_error("Error: header is wrong");

	while(getline(inputfile,line))
	{
		stringstream tokens(line);

		std::string delim;
		std::string date;
		std::string value;
		token >>date>>delim>>value;

		double val;
		if (delim != "|" && !ValidDate(date)){
			std::cout << "Error: bad input => " <<line<<std::endl;
			continue;
		}
		if (!ValidValue(value, val))
		{
			if (val < 0)
				std::cout << "Error: not a positive number"<<std::endl;
			else if (val >1000)
				std::cout << "Error: too large a number"<<std::endl;
			else
				std::cout << "Error: bad input => "<<line <<std::endl;
			continue;
		}


		
		mymap::iterator it = dbmap.lower_bound(date);
		if (it == dbmap.end() || it->first != date)
		{
			if (it == dbmap.begin())
			{
				std::cout << "Error: no earlier date in database => " << line<<std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => "<< value<<" = "<< (val * it->second)<<std::endl;
	}
}
