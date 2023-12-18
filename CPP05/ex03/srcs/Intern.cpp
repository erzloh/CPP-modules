#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
	}
	return *this;
}

static AForm* shrubberyCreation(std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm* presidentialPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

static AForm* robotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	std::string formName[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*getForm[])(std::string target) = {
		shrubberyCreation,
		presidentialPardon,
		robotomyRequest
	};

	for (size_t i = 0; i < 3; i++) {
		if (name == formName[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return getForm[i](target);
		}
	}
	std::cout << "Error: This form doesn't exist" << std::endl;
	return NULL;
}
