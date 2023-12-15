#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
public:
	AForm(const std::string& name, const std::string& target, int gradeRequiredToSign, int gradeRequiredToExecute);
	AForm(const AForm& other);
	~AForm();
	AForm& operator=(const AForm& other);

	std::string	getName() const;
	bool 		isSigned() const;
	int 		getGradeRequiredToSign() const;
	int 		getGradeRequiredToExecute() const;
	std::string	getTarget() const;

	void		beSigned(Bureaucrat & b);

	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
    const std::string	name;
	const std::string	target;
    const int			gradeRequiredToSign;
    const int			gradeRequiredToExecute;
    bool 				signedStatus;
};

std::ostream & operator<<(std::ostream & o, const AForm & rhs);

#endif