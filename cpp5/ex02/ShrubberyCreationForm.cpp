#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("shrubbery",false,145,137),target("nothing")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, false, 145,137),target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other): AForm(other)
{
	target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char* ShrubberyCreationForm::openingFileFailed::what() const throw()
{
	return "file failed to open";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	executor.executeForm(*this);
	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
		throw openingFileFailed();
	file << "        /\\           /\\    \n";
	file << "       /  \\         /  \\   \n";
	file << "      /    \\       /    \\  \n";
	file << "       ----         ----    \n";
	file << "        ||           ||     \n";
	file << "        /\\    \n";
	file << "       /  \\   \n";
	file << "      /    \\  \n";
	file << "       ----    \n";
	file << "        ||   	\n";
	file.close();
}


