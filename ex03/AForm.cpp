
#include <AForm.hpp>

AForm::AForm(): name("unknown"), isSigned(false), gradeSign(2), gradeExec(1)
{
}
AForm::~AForm(){}

AForm::AForm(std::string const name, bool is_signed, int const gradesign, int const gradeexec) : name(name),isSigned(is_signed), gradeSign(gradesign), gradeExec(gradeexec)
{
	if(gradeSign < 1 || gradeExec < 1)
		throw GradeTooLowException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : name(other.name), gradeSign(other.gradeSign), gradeExec(other.gradeExec)
{
	this->isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

int AForm::get_gradeSign() const 
{
	return this->gradeSign;
}
int AForm::get_gradeExec() const
{
	return this->gradeExec;
}
const std::string AForm::get_name() const
{
	return this->name;
}
bool AForm::get_isSigned() const
{
	return this->isSigned;
}

void	AForm::beSigned(Bureaucrat& other)
{
	if (other.getGrade() > this->gradeSign)
		throw Bureaucrat::GradeTooLowException();
	else if (this->isSigned == false)
		this->isSigned = true;
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "AForm, grade too low";
}
const char* AForm::GradeTooHighException::what() const noexcept
{
	return "AForm, grade too High";
}
const char* AForm::NotSigned::what() const noexcept
{
	return "AForm, not signed";
}
std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "AForm name: " << other.get_name() << std::endl;
	os<< "is signed : "<< other.get_isSigned() << std::endl;
	os << "gradeSign: "<< other.get_gradeSign() << std::endl;
	os << "gradeExec: "<< other.get_gradeExec() << std::endl;
	return os;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!isSigned)
	{
		throw NotSigned();
	}
	else if (executor.getGrade() > gradeExec)
		throw GradeTooLowException();
	Action();
}

