#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1(15, "3mr0");
		//b1.decrease_grade(1);
		ShrubberyCreationForm shrubbery1("ba33");
		b1.signForm(shrubbery1);
		shrubbery1.execute(b1);
		PresidentialPardonForm pre1;
		b1.executeForm(shrubbery1);
		b1.executeForm(pre1);

	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
	try{
		Bureaucrat b2(10, "suffer");
		RobotomyRequestForm Rboto("3mro");
		Rboto.execute(b2);
		b2.signForm(Rboto);
		b2.executeForm(Rboto);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() <<std::endl;
	}
	try{
		Bureaucrat b3(11, "customize");
		PresidentialPardonForm pres2("customize");
		PresidentialPardonForm *pres3 = &pres2; 
		b3.signForm(*pres3);
		b3.executeForm(*pres3);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
