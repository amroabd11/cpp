#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string const name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(int, std::string const);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName()const;
		int	 getGrade()const;
		void increase_grade(int grade);
		void decrease_grade(int grade);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& other);




#endif
