#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat ;

class Form
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeSign;
		int const gradeExec;
	public:
		Form();
		Form(std::string, bool, int const gradeSign, int const gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		int get_gradeSign() const;
		int get_gradeExec() const;
		bool get_isSigned() const;
		const std::string get_name() const;
		void	beSigned(Bureaucrat& other);
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const;
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const;
		};
};
std::ostream& operator<<(std::ostream& os, const Form& other);

#endif
