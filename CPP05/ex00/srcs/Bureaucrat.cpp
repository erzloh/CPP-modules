#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150) {
		throw GradeTooLowException();
	} else if (grade < 1) {
		throw GradeTooHighException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other.getName()), _grade(other.getGrade()){
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
	_grade = other.getGrade();

	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade == 1) {
		throw GradeTooHighException();
	} else {
		_grade--;
	}
}

void	Bureaucrat::decrementGrade() {
	if (_grade == 150) {
		throw GradeTooLowException();
	} else {
		_grade++;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low.";
}

std::ostream & operator<<(std::ostream & o, const Bureaucrat & rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (o);
}