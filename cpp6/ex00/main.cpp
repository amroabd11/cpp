#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **v)
{
	(void)argc;
//	const int n = 5;
//	const int* ptr = &n;
//	std::cout << *ptr<<std::endl;
//	int *notConst = const_cast<int*>(ptr);
//	*notConst = 100;
//	std::cout << *ptr<<std::endl;
	std::string con = v[1];
	ScalarConverter::convert(con);
}
