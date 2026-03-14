#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other) 
{
	(void)other;
	return *this;
}

AForm* shrubberyCreate(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
AForm* presedentialPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
AForm* robotomyRequest(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string names[3] = {
		"shrubberycreation",
		"presedentialpardon",
		"robotomyrequest"
	};
	AForm* (*myForms[3])(const std::string& ) = {
		&shrubberyCreate,
		&presedentialPardon,
		&robotomyRequest
	};
	for( int i = 0; i < 3;i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates "<<  name<<std::endl;
			return myForms[i](target);
		}
	}
	std::cout <<"Intern error the form " << name << " doesn't exist"<<std::endl;
	throw std::runtime_error("not found");
	return NULL;
}
