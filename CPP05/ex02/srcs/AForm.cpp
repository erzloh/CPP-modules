#include "AForm.hpp"

AForm::AForm(const std::string& name, const std::string& target, int gradeRequiredToSign, int gradeRequiredToExecute)
	    : name(name), target(target), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute), signedStatus(false) {}

AForm::AForm(const AForm& other)
    : name(other.name), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute), signedStatus(other.signedStatus) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}

std::string	AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

std::string AForm::getTarget() const {
    return target;
}

void AForm::beSigned(Bureaucrat & b) {
    if (b.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    else
        signedStatus = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream & operator<<(std::ostream & o, const AForm & rhs) {
    o << rhs.getName() << ", grade required to sign: " << rhs.getGradeRequiredToSign() << ", grade required to execute: " << rhs.getGradeRequiredToExecute() << ", signed status: " << (rhs.isSigned() ? "Signed" : "Not signed");
    return o;
}