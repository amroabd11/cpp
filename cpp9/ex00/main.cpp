#include "BitcoinExchange.hpp"

int main(int argc, char** v){
	
	std::ifstream inputfile(v[1]);

	mymap dbmap;
	try{
		parse_csv(dbmap);
		process_data(inputfile, dbmap);
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
}
