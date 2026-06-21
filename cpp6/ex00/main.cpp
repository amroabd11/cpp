#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **v)
{
//	const int n = 5;
//	const int* ptr = &n;
//	std::cout << *ptr<<std::endl;
//	int *notConst = const_cast<int*>(ptr);
//	*notConst = 100;
//	std::cout << *ptr<<std::endl;
	if (argc == 2){
		std::string con = v[1];
		try{
			ScalarConverter::convert(con);
		}
		catch (std::exception& e){
			std::cout << e.what()<<std::endl;
		}
		return 0;
	}
	std::cout << "accepts one argument"<<std::endl;
}
