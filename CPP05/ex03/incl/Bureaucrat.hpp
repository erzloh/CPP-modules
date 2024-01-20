#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & other);
	~Bureaucrat();
	Bureaucrat & operator=(const Bureaucrat & other);

	std::string	getName() const;
	int			getGrade() const;

	void		incrementGrade();
	void		decrementGrade();

	void		signForm(AForm & f);
	void		executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;
};

std::ostream & operator<<(std::ostream & o, const Bureaucrat & rhs);

#endif