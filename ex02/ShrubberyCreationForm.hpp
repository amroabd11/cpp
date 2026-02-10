#ifndef SHRUBBERY_REQUEST_FORM_HPP
#define SHRUBBERY_REQUEST_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& other);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
		~ShrubberyCreationForm();
		class openingFileFailed : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		void	Action()const;
};

#endif
