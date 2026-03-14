#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("roboto", false,72,45), target("nothing")
{}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, false, 72,45) ,target(target)
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	target = other.target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::cout << "drilling noises ..."<<std::endl;
	srand(time(0));
	if (rand() % 100 >= 50)
		std::cout << target << " has been robotomized succefully"<<std::endl;
	else
		std::cout << "Robotomy failed"<<std::endl;
}
