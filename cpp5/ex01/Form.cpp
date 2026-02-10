
#include <Form.hpp>

Form::Form(): name("unknown"), isSigned(false), gradeSign(2), gradeExec(1)
{
}
Form::~Form(){}

Form::Form(std::string const name, bool is_signed, int const gradesign, int const gradeexec) : name(name),isSigned(is_signed), gradeSign(gradesign), gradeExec(gradeexec)
{
	if(gradeSign < 1 || gradeExec < 1)
		throw GradeTooLowException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : name(other.name), gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
	this->isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

int Form::get_gradeSign() const 
{
	return this->gradeSign;
}
int Form::get_gradeExec() const
{
	return this->gradeExec;
}
const std::string Form::get_name() const
{
	return this->name;
}
bool Form::get_isSigned() const
{
	return this->isSigned;
}

void	Form::beSigned(Bureaucrat& other)
{
	if (other.getGrade() > this->gradeSign)
		throw Bureaucrat::GradeTooLowException();
	else if (this->isSigned == false)
		this->isSigned = true;
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form, grade too low";
}
const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form, grade too High";
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "Form name: " << other.get_name() << std::endl;
	os<< "is signed : "<< other.get_isSigned() << std::endl;
	os << "gradeSign: "<< other.get_gradeSign() << std::endl;
	os << "gradeExec: "<< other.get_gradeExec() << std::endl;
	return os;
}


