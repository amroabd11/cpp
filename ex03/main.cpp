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
		PresidentialPardonForm pre1;
		b1.executeForm(shrubbery1);
		b1.executeForm(pre1);

	}
	catch(std::exception& e)
	{
		std::cout << e.what()<<std::endl;
	}
}
