#include "BitcoinExchange.hpp"

int main(int argc, char** v){
	
	std::ifstream inputfile;
	try{
		parse_data(v[1], inputfile);
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
}
