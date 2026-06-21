#include "ScalarConverter.hpp"
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cfloat>

void	specialLiteral(std::string& str)
{
	std::cout <<"char: impossible"<<std::endl;
	std::cout << "int: impossible"<<std::endl;
	if (str == "nanf" || str == "+inff" || str == "-inff")
	{
		std::cout << "float: "<<str<<std::endl;
		if (str == "nanf")
			std::cout << "double: nan"<<std::endl;
		else if (str == "+inff")
			std::cout << "double: +inf"<<std::endl;
		else
			std::cout << "double: -inf"<<std::endl;
	}
	else{
		std::cout << "float: "<< str<<"f"<<std::endl;
		std::cout << "double: "<< str<<std::endl;
	}
}

void	ScalarConverter::convert( std::string &str)
{
	std::cout <<std::fixed << std::setprecision(1);
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff"){
		specialLiteral(str);
		return ;
	}
	char *end;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		std::cout << "char: "<<str[1]<<std::endl;
		std::cout << "int: "<<static_cast<int>(str[1])<<std::endl;
		std::cout << "float: "<<static_cast<float>(str[1])<<"f"<<std::endl;
		std::cout << "double: "<<static_cast<double>(str[1])<<std::endl;
		return ; 
	}
	double ret = std::strtod(str.c_str(), &end);

	if ((std::strcmp(end, "f") != 0) && end[0] != '\0'){
		std::cout << "'"<<end<<"'"<<std::endl;
		throw std::runtime_error("wrong intput stupid hacker!!");
	}
	if (ret >= 0 && ret <= 126 ){
		if (std::isprint(static_cast<int>(ret))){
			std::cout << "char: "<<static_cast<char>(ret)<<std::endl;
			std::cout << "int: "<<static_cast<int>(ret)<<std::endl;
			std::cout << "float: "<<static_cast<float>(ret)<<"f"<<std::endl;
			std::cout << "double: "<<static_cast<double>(ret)<<std::endl;
		}
		else{
			std::cout << "char: Non displayable"<<std::endl;
			std::cout << "int: "<<static_cast<int>(ret)<<std::endl;
			std::cout << "float: "<<static_cast<float>(ret)<<"f"<<std::endl;
			std::cout << "double: "<<static_cast<double>(ret)<<std::endl;
		}
	}
	else if(ret > INT_MAX || ret < INT_MIN ){
		std::cout << "char: impossible"<<std::endl;
		std::cout << "int: impossible"<<std::endl;
		std::cout << "float: "<<static_cast<float>(ret)<<"f"<<std::endl;
		std::cout << "double: "<<static_cast<double>(ret)<<std::endl;
	}
	else if (ret < INT_MAX && ret > INT_MIN){
		std::cout << "char: impossible"<<std::endl;
		std::cout << "int: "<<static_cast<int>(ret)<<std::endl;
		std::cout<<  "float: " <<static_cast<float>(ret)<<"f"<<std::endl;
		std::cout<< "double: " <<static_cast<double>(ret)<<std::endl;
	}

}





