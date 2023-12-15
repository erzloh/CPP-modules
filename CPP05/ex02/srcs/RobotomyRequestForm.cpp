#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw GradeTooLowException();
    } else if (!isSigned()) {
		throw FormNotSignedException();
	}

	std::cout << "* drilling noises * ";
	std::srand(std::time(NULL));
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << getTarget() << " robotomization failed." << std::endl;
	}
}
