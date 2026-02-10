#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(): AForm("presidential", false,25, 5), target("nothing")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", false, 25,5),target(target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other) 
{
	target = other.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


void PresidentialPardonForm::Action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
