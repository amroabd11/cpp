#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("unkown"), grade(150)
{
}
Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(int grade, std::string const name): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name), grade(other.grade)
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::increase_grade(int grade)
{
	this->grade -= grade;
	if (this->grade < 1)
		throw GradeTooLowException();
	if (this->grade > 150)
		throw GradeTooHighException();
}

void	Bureaucrat::decrease_grade(int grade)
{
	this->grade += grade;
	if (this->grade > 150)
		throw GradeTooHighException();
	if (this->grade< 1)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& other)
{
	try{
		other.beSigned(*this);
	}
	catch(std::exception& e)
	{
		std::cout << name << " couldn't sign " << other.get_name()<< " because " << e.what()<<std::endl;
		return ;
	}
	std::cout << name << " signed " << other.get_name()<<std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("grade too low");
}
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("grade too high");
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.get_name()<<std::endl;
	}
	catch(std::exception const& e)
	{
		std::cout << name << " couldn't execute signing because " << e.what()<<std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other)
{
	os << other.getName() <<", bureaucrat grade "<< other.getGrade() << std::endl ;
	return os;
}
