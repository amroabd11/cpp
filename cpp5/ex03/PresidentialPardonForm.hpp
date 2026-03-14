#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private: 
		std::string  target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string );
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
		~PresidentialPardonForm();
		void	execute(Bureaucrat const & executor) const;
};


#endif
