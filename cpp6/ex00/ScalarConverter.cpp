#include "ScalarConverter.hpp"
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cfloat>

//void	convert_toChar(std::string& ch)
//{
//	char one = str[1];
//		if (std::isprint(one))
//		{
//			std::cout << "char: " << str[1]<<std::endl;
//			std::cout << "int: " << static_cast<int>(str[1])<<std::endl;
//			std::cout << "float: "<< static_cast<float>(str[1])<<"f" << std::endl;
//			std::cout << "double: "<< static_cast<double>(str[1]) << std::endl;
//		}
//		else{
//			std::cout << "char : Non displayable"<<std::endl;
//			std::cout << "int: " << static_cast<int>(str[1])<<std::endl;
//			std::cout << "float: " << static_cast<float>(str[1])<< "f"<<std::endl;
//			std::cout << "double: " << static_cast<double>(str[1])<<std::endl;
//		}
//}

void	ScalarConverter::convert( std::string &str)
{
//	if ()//TODO THIS IF will handle the special cases such as inf -inf nanf -nanf
//	{}
	char *end;
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		std::cout << "char: "<<str[1]<<std::endl;
		std::cout << "int: "<<static_cast<int>(str[1])<<std::endl;
		std::cout << "float: "<<static_cast<float>(str[1])<<"f"<<std::endl;
		std::cout << "char: "<<static_cast<double>(str[1])<<std::endl;
		return ; 
	}
	double ret = std::strtod(str.c_str(), &end);

	if ((std::strcmp(end, "f") != 0) && end[0] != '\0'){
		std::cout << "'"<<end<<"'"<<std::endl;
		throw std::runtime_error("wrong intput stupid hacker!!");
	}
	if (ret >= 32 && ret <= 126 ){
		std::cout << "char: "<<static_cast<char>(ret)<<std::endl;
		std::cout << "int: "<<static_cast<int>(ret)<<std::endl;
		std::cout << "float: "<<static_cast<float>(ret)<<"f"<<std::endl;
		std::cout << "double: "<<static_cast<double>(ret)<<std::endl;
	}
	else if(ret > DBL_MAX || ret < DBL_MIN){
		std::cout << DBL_MAX<<std::endl;
		std::cout << DBL_MIN<<std::endl;
		std::cout << "no conversion possible the num is greather then doubles"<<std::endl;
	}
	else if(ret > INT_MAX || ret < INT_MIN ){
		std::cout << "char: impossible"<<std::endl;
		std::cout << "int: out of int bounds"<<std::endl;
		std::cout << "float: "<<static_cast<float>(ret)<<"f"<<std::endl;
		std::cout << "double: "<<static_cast<double>(ret)<<std::endl;
	}
	else if(ret > DBL_MAX || ret < DBL_MIN)
		std::cout << "all conversions are impossible"<<std::endl;

}





