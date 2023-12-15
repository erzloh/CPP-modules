#include "Form.hpp"

Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
	    : name(name), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute), signedStatus(false) {}

Form::Form(const Form& other)
    : name(other.name), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute), signedStatus(other.signedStatus) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}

std::string	Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat & b) {
    if (b.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    else
        signedStatus = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream & operator<<(std::ostream & o, const Form & rhs) {
    o << rhs.getName() << ", form grade required to sign: " << rhs.getGradeRequiredToSign() << ", grade required to execute: " << rhs.getGradeRequiredToExecute() << ", signed status: " << (rhs.isSigned() ? "Signed" : "Not signed");
    return o;
}