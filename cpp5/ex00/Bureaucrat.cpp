#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): name("unkown"), grade(150)
{

}
Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(int grade, std::string const name): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
	if (this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::decrease_grade(int grade)
{
	this->grade += grade;
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade< 1)
		throw GradeTooHighException();
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other)
{
	os << other.getName() <<", bureaucrat grade "<< other.getGrade() << std::endl ;
	return os;
}
