#include "BitcoinExchange.hpp"


bool isLeapYear(int year)
{
	return (year%4 == 0 && year %100 !=0) || (year %400 ==0);
}


bool ValidDate(std::string date)
{
	if (date.length() != 10)
		return false;
	int year=0;
	int month=0;
	int day=0;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i=0; i<date.length(); i++)
	{
		if( i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	year = std::atoi(date.substr(0,4).c_str());
	month = std::atoi(date.substr(5,2).c_str());
	day = std::atoi(date.substr(8,2).c_str());
	if (year < 0)
		return false;
	if(month < 1 || month > 12)
		return false;
	int daysOFmonth[]= {31, 28,31,30,31,30,31,31,30,31,30,31};
	int maxday = daysOFmonth[month-1];
	if (month ==2 && isLeapYear(year))
		maxday=29;
	if (day < 1 || day >maxday)
		return false;
	return true;
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
		if (pos == std::string::npos)
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
	if( *end!='\0' || value.empty() || val <0 || val > 1000)
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

	while(std::getline(inputfile,line))
	{
		std::stringstream tokens(line);

		std::string delim;
		std::string date;
		std::string value;
		tokens >>date>>delim>>value;

		double val;
		if (delim != "|" || !ValidDate(date)){
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
