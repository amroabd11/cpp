#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat ;

class AForm
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeSign;
		int const gradeExec;
	public:
		AForm();
		AForm(std::string, bool, int const gradeSign, int const gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		int get_gradeSign() const;
		int get_gradeExec() const;
		bool get_isSigned() const;
		const std::string get_name() const;
		void	beSigned(Bureaucrat& other);
		// virtual void	Action()const = 0;
		virtual void	execute(Bureaucrat const & executor) const= 0;
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif
