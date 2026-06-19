#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string &str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
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
}
