#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Bureaucrat;

class Form {
public:
	Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute);
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);

	std::string	getName() const;
	bool 		isSigned() const;
	int 		getGradeRequiredToSign() const;
	int 		getGradeRequiredToExecute() const;

	void		beSigned(Bureaucrat & b);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

private:
    const std::string	name;
    const int			gradeRequiredToSign;
    const int			gradeRequiredToExecute;
    bool 				signedStatus;
};

std::ostream & operator<<(std::ostream & o, const Form & rhs);

#endif