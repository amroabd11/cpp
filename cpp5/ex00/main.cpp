
#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat b1;
		b1.increase_grade(1);
		Bureaucrat b2(19,"3mro");
		std::cout << b1;
		std::cout << b2;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
	try{
		Bureaucrat b3;
		Bureaucrat b4 = b3;
		std::cout << b3;
		b4.decrease_grade(1);
		std::cout << b4;

	}catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
	try{
		Bureaucrat j(1000,"brug");
	}catch(std::exception& e)
	{
		std::cout <<e.what()<<std::endl;
	}

}
