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

void RobotomyRequestForm::Action() const
{
	std::cout << "drilling noises ..."<<std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized succefully"<<std::endl;
	else
		std::cout << "Robotomy failed"<<std::endl;
}
