#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1(3, "3mr0");
		//b1.decrease_grade(1);
		Form f1;
		b1.signForm(f1);
		Form f2("blaBla" ,false, 10,1);
		b1.signForm(f2);
		std::cout << f1;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
}
