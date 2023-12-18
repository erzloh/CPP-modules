#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Bureaucrat b("Eric", 2);
		std::cout << b << std::endl;

		// ShrubberyCreationForm s("target");
		// std::cout << s << std::endl;

		// RobotomyRequestForm r("target");
		// std::cout << r << std::endl;

		// PresidentialPardonForm p("target");
		// std::cout << p << std::endl;

		// b.incrementGrade();

		// b.signForm(s);
		// std::cout << s << std::endl;

		// b.signForm(r);
		// std::cout << r << std::endl;

		// b.signForm(p);
		// std::cout << p << std::endl;

		// b.executeForm(s);
		// b.executeForm(r);
		// b.executeForm(p);

		// Test Intern
		Intern i;

		AForm* f1 = i.makeForm("shrubbery creation", "target");
		std::cout << *f1 << std::endl;
		b.signForm(*f1);
		b.executeForm(*f1);
		delete f1;

		AForm* f2 = i.makeForm("robotomy request", "target");
		std::cout << *f2 << std::endl;
		b.signForm(*f2);
		b.executeForm(*f2);
		delete f2;

		AForm* f3 = i.makeForm("presidential pardon", "target");
		std::cout << *f3 << std::endl;
		b.signForm(*f3);
		b.executeForm(*f3);
		delete f3;

		AForm* f4 = i.makeForm("error", "target");
		(void)f4;

	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
	// } catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Form::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Form::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// }
	
	return 0;
}
