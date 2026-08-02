#include "RPN.hpp"

int main(int argc, char** v)
{
	if (argc != 2)
	{
		std::cerr << "needs argument"<<std::endl;
		return 1;
	}
	std::string expression(v[1]);
	try{
		parse_input(expression);
	}
	catch(...)
	{
		return 1;
	}
	calcul(expression);
}

