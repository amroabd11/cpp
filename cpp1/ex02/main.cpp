#include <iostream>

int main()
{
	std::string str;
	str = "HI THIS IS BRAIN";
	std::string *stringPTR=&str;
	std::string &stringREF = str;
	std::cout << "address of string: "<<&str<<std::endl;
	std::cout << "address of stringPTR: "<<stringPTR<<std::endl;
	std::cout << "address of stringREF: "<<&stringREF<<std::endl;
	std::cout << "value of string: "<<str<<std::endl;
	std::cout << "value pointed by stringPTR: "<<*stringPTR<<std::endl;
	std::cout << "value pointed by stringREF: "<<stringREF<<std::endl;
}


