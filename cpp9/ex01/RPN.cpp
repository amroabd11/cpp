#include "RPN.hpp"

void parse_input(std::string expression)
{
	std::string token;
	std::istringstream iss(expression);
	while(std::getline(iss, token, ' '))
	{
		if(token.length() > 1)
		{
			throw std::logic_error("only digits accepted");
		}
		if (token != "+" && token != "-" && token != "/" && token != "*"
			&& !std::isdigit(token[0]))
		{
			std::cout << token[0]<<std::endl;
			throw std::logic_error("Error: expression syntax is wrong");
		}
	}
}

void calcul(std::string expr)
{
	std::stack<int, std::list<int> > stak;
	std::string num = "";
	for(size_t i =0; i< expr.size();i++)
	{
		if (expr[i] == ' ')
			continue;
		if(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/')
		{
			num += expr[i];
			stak.push(std::atoi(num.c_str()));
		//	std::cout << stak.top() <<std::endl;
			num = "";
			continue;
		}
		else
		{
			long result = 0;
			if (stak.size() < 2)
				throw std::logic_error("invalid expression: insufficient operands");
			long b = stak.top();
			stak.pop();
			long a = stak.top();
			stak.pop();
			if(expr[i] == '+')
				result = a+b;
			else if(expr[i] == '-')
				result = a-b;
			else if(expr[i] == '*')
				result = a*b;
			else{
				if (b == 0)
					throw std::logic_error("division by 0 is invalid");
				result = a/b;
			}
			if (result > INT_MAX || result< INT_MIN)
				throw std::logic_error("Error");
			stak.push(result);
		}
	}
	if (stak.size() != 1)
		throw std::logic_error("invalid expression: leftover operands");
	std::cout << stak.top()<<std::endl;
}




