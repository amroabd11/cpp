
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1;
		b1.increase_grade(1);
		std::cout << b1;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}

}
