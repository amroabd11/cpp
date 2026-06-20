#include "ScalarConverter.hpp"

void	convert_toChar(std::string& ch)
{
	char one = str[1];
		if (std::isprint(one))
		{
			std::cout << "char: " << str[1]<<std::endl;
			std::cout << "int: " << static_cast<int>(str[1])<<std::endl;
			std::cout << "float: "<< static_cast<float>(str[1])<<"f" << std::endl;
			std::cout << "double: "<< static_cast<double>(str[1]) << std::endl;
		}
		else{
			std::cout << "char : Non displayable"<<std::endl;
			std::cout << "int: " << static_cast<int>(str[1])<<std::endl;
			std::cout << "float: " << static_cast<float>(str[1])<< "f"<<std::endl;
			std::cout << "double: " << static_cast<double>(str[1])<<std::endl;
		}
}

void	ScalarConverter::convert(std::string &str)
{
	if ()//TODO THIS IF will handle the special cases such as inf -inf nanf -nanf
	{}
	char *end;
	double ret = std::strtod(str, end);
	if (!end)
		throw std::runtime_error("wrong intput stupid hacker!!");
	if (ret >= 32 && ret <= 126 )



}
