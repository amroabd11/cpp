#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
		PresidentialPardonForm pre1;
		b1.executeForm(shrubbery1);
		shrubbery1.execute(b1);

	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
///////////////////////////////////////////////////////////////////
	try
	{
		Bureaucrat b2;
		b2.increase_grade(100);
		Intern i1;
		AForm* rrf;
		rrf = i1.makeForm("shrubberycreation", "blabla");
		b2.signForm(*rrf);
		rrf->execute(b2);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
////////////////////////////////////////////////////////////////////
	try
	{
		Bureaucrat b4(1, "gungster");
		//b4.increase_grade(99);
		Intern i2;
		AForm *f1;
		f1 = i2.makeForm("robotomyrequest", "kicker");
		b4.signForm(*f1);
		f1->execute(b4);
		b4.executeForm(*i2.makeForm("robotomyrequest", "kick"));
	}catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b5(0, "jester");
		b5.increase_grade(99);
	}catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
