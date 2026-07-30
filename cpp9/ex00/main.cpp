#include "BitcoinExchange.hpp"

int main(int argc, char** v){
	
	std::ifstream inputfile(v[1]);
	std::ifstream dbfile("data.csv");

	mymap inputmap;
	mymap dbmap;
	try{
		parse_data(inputfile, inputmap, '|');
		parse_data(dbfile, dbmap, ',');
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
}
