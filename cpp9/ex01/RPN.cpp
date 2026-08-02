#include "RPN.hpp"

void parse_input(std::string expression)
{
	std::string token;
	std::istringstream iss(expression);
	while(std::getline(iss, token, ' '))
	{
		if(token.length() > 1)
		{
			std::cerr << "only digits accepted"<<std::endl;
			throw std::logic_error("");
		}
		if (token != "+" && token != "-" && token != "/" && token != "*"
			&& !std::isdigit(token[0]))
		{
			std::cout << token[0]<<std::endl;
			std::cerr << "Error: expression syntax is wrong"<<std::endl;
			throw std::logic_error("");
		}
	}
}

void calcul(std::string expr)
{
	std::stack<int> stak;
	for(size_t i =0; i< expr.size();i++)
	{
		if(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/')
		{
			stak.push(std::atoi(&expr[i]));
			continue;
		}
		else
		{
			int b = stak.top();
			stak.pop();
			int a = stak.top();
			stak.pop();
			if(expr[i] == '+')
				stak.push(a+b);
			else if(expr[i] == '-')
				stak.push(a-b);
			else if(expr[i] == '*')
				stak.push(a*b);
			else
				stak.push(a/b);
		}
	}
	std::cout << stak.top()<<std::endl;
}




